#!/bin/bash
echo "CS354 SP22 Project 2 Sample Tests"
echo "by Ruixuan Tu"
cd ..
echo "pwd: $(pwd)"

echo "=== Simple Tests Begin ==="

rm tester.c
cp simple.c tester.c

for i in {1..8}
do
        echo Simple $i
        make clean
        cat samples/$i-simple.txt | sed 3q | sed 's/.*: //g' > test/in.txt
        cat samples/$i-simple.txt | sed '1,3d' > test/ans.txt
        make test
        make clean
done

echo "=== Simple Tests End ==="

echo "=== Detail Tests Begin ==="

rm tester.c
cp detail.c tester.c

for i in {1..3}
do
        echo Detail $i
        make clean
        cat samples/$i-detail.txt | sed 5q | sed 's/.*: //g' > test/in.txt
        cat samples/$i-detail.txt | sed '1,5d' | sed 's/.* Half: .*//g' > test/ans.txt
        make test
        make clean
done

echo "=== Detail Tests End ==="

rm tester.c
