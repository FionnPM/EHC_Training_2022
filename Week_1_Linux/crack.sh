#!/bin/bash

for i in {0..999}
do
        for j in {a..z}
        do
                for k in {a..z}
                do
                        pass=`printf "%03d" $i`$j$k
                        echo $pass
                        status=`7z x crackit.7z -p$pass`
                        if [[ $status != *"Errors"* ]]; then
                                exit
                        fi
                done
        done
done
