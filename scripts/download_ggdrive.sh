# read -a arr
# j=0
for FILEID in `cat input.txt`
do
    # i=${arr[$j]}
    FILENAME="[Omamori]_Kimetsu_no_Yaiba_(Mugen_Ressha)_01.mp4"
    wget --load-cookies /tmp/cookies.txt "https://drive.google.com/uc?export=download&confirm=$(wget --quiet --save-cookies /tmp/cookies.txt --keep-session-cookies --no-check-certificate "https://drive.google.com/uc?export=download&id=$FILEID" -O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')&id=$FILEID" -O $FILENAME && rm -rf /tmp/cookies.txt
    # echo "Download episode_$i complete"
    echo "Download movie complete"
    # j=$((j + 1))
done
