#!/bin/bash
fileName=$1
firstLine=$2
lastLine=$3

#awk 'NR >= $firstLine && NR <= $lastLine' $fileName
#sed '{$firstLine}, {$lastLine}p' {$fileName}
sed -n "$firstLine, $lastLine p" ./$fileName
