clear

# Clean build always lol
echo "**** Cleaning ****"
rm -r out
mkdir out
make O=out clean
make clean && make distclean && make mrproper

# auto clang cloner/updater
echo "**** Cleaning ****"
if [ -r clang ]; then
  echo "clang found! check for update..."
  cd clang
  git config pull.rebase true
  git pull
  cd ..

else
  echo "clang not found!, git cloning it now...."
  git clone https://github.com/kdrag0n/proton-clang.git --depth=1 clang

fi


KERNEL_DEFCONFIG=lisa_defconfig
Device="Xiaomi 11 Lite NE (lisa)"
ANYKERNEL3_DIR=$PWD/anykernel3/
KERNELDIR=$PWD/
FINAL_KERNEL_ZIP=B⚡️LT:Revolution.zip
export PATH="${PWD}/clang/bin:${PATH}"
export ARCH=arm64
export SUBARCH=arm64
export KBUILD_COMPILER_STRING="$(${PWD}/clang/bin/clang --version | head -n 1 | perl -pe 's/\(http.*?\)//gs' | sed -e 's/  */ /g' -e 's/[[:space:]]*$//')"
# Speed up build process
MAKE="./makeparallel"

BUILD_START=$(date +"%s")
blue='\033[0;34m'
cyan='\033[0;36m'
yellow='\033[0;33m'
red='\033[0;31m'
green='\033[0;32m'
nocol='\033[0m'

echo ""
echo -e "$blue***********************************************"
echo "**** Kernel defconfig is set to $KERNEL_DEFCONFIG ****"
echo -e "***********************************************$nocol"
echo "--------------------------------------------------------"
echo -e "$blue***********************************************"
echo "            BUILDING KERNEL          "
echo -e "***********************************************$nocol"
echo ""
make $KERNEL_DEFCONFIG O=out
make -j$(nproc --all) O=out \
                      ARCH=arm64 \
                      CC=clang \
                      CROSS_COMPILE=aarch64-linux-gnu- \
                      CROSS_COMPILE_ARM32=arm-linux-gnueabi- \
                      NM=llvm-nm \
                      OBJCOPY=llvm-objcopy \
                      OBJDUMP=llvm-objdump \
                      STRIP=llvm-strip

echo "**** Verify Image.gz-dtb ****"
if [ -f out/arch/arm64/boot/Image.gz-dtb ]; then
  echo "**** Removing leftovers ****"
  rm -rf $ANYKERNEL3_DIR/Image.gz-dtb
  rm -rf $ANYKERNEL3_DIR/$FINAL_KERNEL_ZIP

  echo "**** Copying Image.gz-dtb ****"
  cp $PWD/out/arch/arm64/boot/Image.gz-dtb $ANYKERNEL3_DIR/

  echo "**** Time to zip up! ****"
  cd $ANYKERNEL3_DIR/
  zip -r9 $FINAL_KERNEL_ZIP * -x README $FINAL_KERNEL_ZIP
  cp $ANYKERNEL3_DIR/$FINAL_KERNEL_ZIP $KERNELDIR/$FINAL_KERNEL_ZIP
  echo "**** Done, here is your build info ****"

  BUILD_END=$(date +"%s")
  DIFF=$(($BUILD_END - $BUILD_START))
  echo -e "$yellow Device:-$Device.$nocol"
  echo -e "$yellow Build Time:- Completed in $(($DIFF / 60)) minute(s) and $(($DIFF % 60)) seconds.$nocol"

else
  echo "**** Build Failed ****"
  echo "**** Removing leftovers ****"
  rm -rf $ANYKERNEL3_DIR/$FINAL_KERNEL_ZIP
  rm -rf $ANYKERNEL3_DIR/Image.gz-dtb
  rm -rf out/
  BUILD_END=$(date +"%s")
  DIFF=$(($BUILD_END - $BUILD_START))
  echo -e "$red mission failed we'll get em next time, Build failed in:- $(($DIFF / 60)) minute(s) and $(($DIFF % 60)) seconds.$nocol"
fi
