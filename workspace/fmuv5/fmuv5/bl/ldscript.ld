/* generated ldscript.ld */
MEMORY
{
    flash : org = 0x08000000, len = 2048K
    ram0  : org = 0x20020000, len = 393216
}

INCLUDE common.ld
