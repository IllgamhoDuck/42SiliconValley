#!/bin/sh
declare -a arr=("some_guy" "bsq_h" "google_guy")
declare -a output=("out1" "out2" "out3")
arrlength=${#arr[@]}

# echo "Building Maps..."
# echo "The maps are huge, please be patient..."
# echo "Regular cases"
# ./generate_map.pl 10 10 2 > small_mp
# ./generate_map.pl 500 500 15 > med_mp
# ./generate_map.pl 1000 1000 20 > big_mp
# ./generate_map.pl 1000 1000 0 > big_empty_mp
# ./generate_map.pl 100000 10 200 > long_rect_mp
# ./generate_map.pl 10000 10000 500 > stress_mp

# echo "Edge cases"
# echo  -e "\n" > empty_mp
# echo  -e "1.ox\n" > empty_mp2

echo "Normal Tests"
echo "Test 01: Small Map"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} small_mp > ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Test 02: Medium Map"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} med_mp >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Test 03: Big Map"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} big_mp >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Test 04: Big Empty Map"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} big_empty_mp >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Test 05: Medium Map"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} long_rect_mp >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Test 06: Empty Map1 --> Expect errors : )"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} empty_mp >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Test 07: Empty Map2 --> Expect errors again"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} empty_mp2 >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Test 08: Multiple Files No Errors"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} small_mp med_mp big_mp >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Test 09: Multiple Files With Errors"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} small_mp empty_mp med_mp empty_mp2 big_mp >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


echo "Boss Test: Stress Map ............. its not frozen, just wait......."
echo "BTW it might crash lol (<ctrl-c> to quit process)"
for (( i=0; i<${arrlength}; i++ ));
do
	if [ "$i" = 0 ]
		then printf "\nSome Guy's BSQ"
	elif [ "$i" = 1 ]
		then printf "\nYour BSQ"
	else
		printf "\nGoogle Guy's BSQ"
	fi
	time ./${arr[$i]} stress_mp >> ${output[$i]}
	echo "" >> ${output[$i]}
done
echo ""


#diff out1 out2 > google_guy_and_you
#diff out1 out3 > some_guy_and_you
