#ifndef HEXFORMAT_H
#define HEXFORMAT_H

/**
 * @brief convertToHexValues: convert ASCII char value to hex
 * @param value ASCII char value
 * @return hex value
 */
char convertToHexValues(char value)
{
        if(value >= '0' && value <= '9')
        {
            value = value - 0x30;
        }

        if(value >= 'A' && value <= 'F')
        {
            value = value - 0x37;
        }

        if(value >= 'a' && value <= 'f')
        {
            value = value - 0x57;
        }

    return value;
}

#endif // HEXFORMAT_H
