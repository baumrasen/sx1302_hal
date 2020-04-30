/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
  (C)2019 Semtech

Description:
    Functions used to handle LoRa concentrator SX1255/SX1257 radios.

License: Revised BSD License, see LICENSE.TXT file include in the project
*/

/* -------------------------------------------------------------------------- */
/* --- DEPENDANCIES --------------------------------------------------------- */

#include <stdint.h>     /* C99 types */
#include <stdbool.h>    /* bool type */

#include "sx125x_com.h"
#include "sx125x_spi.h"

/* -------------------------------------------------------------------------- */
/* --- PRIVATE MACROS ------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* --- PRIVATE TYPES -------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* --- PRIVATE CONSTANTS ---------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* --- PRIVATE VARIABLES ---------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* --- PRIVATE FUNCTIONS ---------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* --- PUBLIC FUNCTIONS DEFINITION ------------------------------------------ */

/* Simple read */
int sx125x_com_r(void *com_target, uint8_t spi_mux_target, uint8_t address, uint8_t *data) {
    return sx125x_spi_r(com_target, spi_mux_target, address, data);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int sx125x_com_w(void *com_target, uint8_t spi_mux_target, uint8_t address, uint8_t data) {
    return sx125x_spi_w(com_target, spi_mux_target, address, data);
}

/* --- EOF ------------------------------------------------------------------ */
