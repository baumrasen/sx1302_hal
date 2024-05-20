#!/usr/bin/env bash

# This script is intended to be used on SX1302 CoreCell platform, it performs
# the following actions:
#       - export/unpexort GPIO23 and GPIO18 used to reset the SX1302 chip and to enable the LDOs
#       - export/unexport GPIO22 used to reset the optional SX1261 radio used for LBT/Spectral Scan
#
# Usage examples:
#       ./reset_lgw.sh stop
#       ./reset_lgw.sh start

# GPIO mapping has to be adapted with HW
#

GPIO_CHIP="gpiochip0"
RESET_GPIO="23"
POWER_EN_GPIO="18"
POWER_EN_LOGIC="18"

GPIOSET="gpioset -m time -u 100000 ${GPIO_CHIP}"

# Enable gateway
if [[ ${POWER_EN_GPIO} -ne 0 ]]; then
    echo "Concentrator enabled through ${GPIO_CHIP}:${POWER_EN_GPIO} (using libgpiod)"
    ${GPIOSET} ${POWER_EN_GPIO}=${POWER_EN_LOGIC} 2>/dev/null
fi

# Reset gateway
for GPIO in ${RESET_GPIO//,/ }; do
    if [[ ${GPIO} -ne 0 ]]; then
        echo "Concentrator reset through ${GPIO_CHIP}:${GPIO} (using libgpiod)"
        ${GPIOSET} "${GPIO}"=0 2>/dev/null
        ${GPIOSET} "${GPIO}"=1 2>/dev/null
        ${GPIOSET} "${GPIO}"=0 2>/dev/null
    fi
done

exit 0