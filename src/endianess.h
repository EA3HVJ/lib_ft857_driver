#ifndef ENDIANESS_H
#define ENDIANESS_H

#ifdef __cplusplus
extern "C"
{
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define SWAP_ENDIAN
#endif


#ifdef __cplusplus
}
#endif

#endif /* ENDIANESS_H */

