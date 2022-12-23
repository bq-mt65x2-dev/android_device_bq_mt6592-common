#!/bin/sh

rootdirectory="$PWD"
dirs="bionic external/icu external/wpa_supplicant_8 frameworks/av frameworks/base frameworks/opt/telephony packages/apps/Snap system/bt system/core system/netd"

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
	echo "Cleaning $dir patches..."
	git checkout -- . && git clean -df
done

echo "Done!"
cd $rootdirectory
