#!/bin/bash
# This script was made for the QT UofL Lab Status program
# First it gathers the machine names and then runs a ping command with each of them. When the ping comand is run it will check if the recieved and transmitted packets are equal, if they are that means the machine is online.

grep -e "C509" -e "C513" -e "D519" "/root/qt/QT_UofL_Lab_Status/inv/InventoryCN.csv" | cut -d , -f 2 > names.txt
FILE="names.txt"
OUTPUT="machineHealth.txt"

while IFS= read -r name
do
  netInfo="$(ping -c 2 $name | tail -2 | head -1 | cut -c 1-24)"
  transmitted="$(cut -c 1 <<< $netInfo)"
  recieved="$(cut -d ' ' -f 4 <<< $netInfo)"

  if [ $transmitted -eq $recieved ]; then
    status="online"
  else
    status="offline"
  fi

  echo "$name $status"
done <"$FILE"
