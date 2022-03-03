
#include "hal.h"
#include "ref_gcm.h"


///////
// http://csrc.nist.gov/groups/STM/cavp/gcmtestvectors.zip gcmEncryptExtIV128.rsp
// [Keylen = 128]
// [IVlen = 96]
// [PTlen = 128]
// [AADlen = 128]
// [Taglen = 128]
// Count = 0
// K:   c939cc13397c1d37de6ae0e1cb7c423c
// IV:  b3d8cc017cbb89b39e0f67e2
// P:   c3b3c41f113a31b73d9a5cd432103069
// AAD: 24825602bd12a984e0092d3e448eda5f
// C:   93fe7d9e9bfd10348a5606e5cafa7354
// AT:  0032a1dc85f1c9786925a2e71d8272dd
///////
const uint8_t K3[] =  {0xc9, 0x39, 0xcc, 0x13, 0x39, 0x7c, 0x1d, 0x37, 0xde, 0x6a, 0xe0, 0xe1, 0xcb, 0x7c, 0x42, 0x3c};
const uint8_t IV3[] = {0xb3, 0xd8, 0xcc, 0x01, 0x7c, 0xbb, 0x89, 0xb3, 0x9e, 0x0f, 0x67, 0xe2,
					   0x00,0x00,0x00,0x01};
const uint8_t P3[] =  {0xc3, 0xb3, 0xc4, 0x1f, 0x11, 0x3a, 0x31, 0xb7, 0x3d, 0x9a, 0x5c, 0xd4, 0x32, 0x10, 0x30, 0x69};
const uint8_t A3[] =  {0x24, 0x82, 0x56, 0x02, 0xbd, 0x12, 0xa9, 0x84, 0xe0, 0x09, 0x2d, 0x3e, 0x44, 0x8e, 0xda, 0x5f};
#define A3_len sizeof(A3)
const uint8_t C3[] =  {0x93, 0xfe, 0x7d, 0x9e, 0x9b, 0xfd, 0x10, 0x34, 0x8a, 0x56, 0x06, 0xe5, 0xca, 0xfa, 0x73, 0x54};
const uint8_t T3[] =  {0x00, 0x32, 0xa1, 0xdc, 0x85, 0xf1, 0xc9, 0x78, 0x69, 0x25, 0xa2, 0xe7, 0x1d, 0x82, 0x72, 0xdd};

///////
// http://csrc.nist.gov/groups/STM/cavp/gcmtestvectors.zip gcmEncryptExtIV128.rsp
// [Keylen = 128]
// [IVlen = 96]
// [PTlen = 256]
// [AADlen = 128]
// [Taglen = 128]
// Count = 0
// K = 298efa1ccf29cf62ae6824bfc19557fc
// IV = 6f58a93fe1d207fae4ed2f6d
// P = cc38bccd6bc536ad919b1395f5d63801f99f8068d65ca5ac63872daf16b93901
// AAD = 021fafd238463973ffe80256e5b1c6b1
// C = dfce4e9cd291103d7fe4e63351d9e79d3dfd391e3267104658212da96521b7db
// T = 542465ef599316f73a7a560509a2d9f2
///////
const uint8_t K4[] =  {0x29, 0x8e, 0xfa, 0x1c, 0xcf, 0x29, 0xcf, 0x62, 0xae, 0x68, 0x24, 0xbf, 0xc1, 0x95, 0x57, 0xfc};
const uint8_t IV4[] = {0x6f, 0x58, 0xa9, 0x3f, 0xe1, 0xd2, 0x07, 0xfa, 0xe4, 0xed, 0x2f, 0x6d,
						0x00,0x00,0x00,0x01};
const uint8_t P4[] =  {0xcc, 0x38, 0xbc, 0xcd, 0x6b, 0xc5, 0x36, 0xad, 0x91, 0x9b, 0x13, 0x95, 0xf5, 0xd6, 0x38, 0x01, 0xf9, 0x9f, 0x80, 0x68, 0xd6, 0x5c, 0xa5, 0xac, 0x63, 0x87, 0x2d, 0xaf, 0x16, 0xb9, 0x39, 0x01};
const uint8_t A4[] =  {0x02, 0x1f, 0xaf, 0xd2, 0x38, 0x46, 0x39, 0x73, 0xff, 0xe8, 0x02, 0x56, 0xe5, 0xb1, 0xc6, 0xb1};
const uint8_t C4[] =  {0xdf, 0xce, 0x4e, 0x9c, 0xd2, 0x91, 0x10, 0x3d, 0x7f, 0xe4, 0xe6, 0x33, 0x51, 0xd9, 0xe7, 0x9d, 0x3d, 0xfd, 0x39, 0x1e, 0x32, 0x67, 0x10, 0x46, 0x58, 0x21, 0x2d, 0xa9, 0x65, 0x21, 0xb7, 0xdb};
const uint8_t T4[] =  {0x54, 0x24, 0x65, 0xef, 0x59, 0x93, 0x16, 0xf7, 0x3a, 0x7a, 0x56, 0x05, 0x09, 0xa2, 0xd9, 0xf2};

///////
// http://csrc.nist.gov/groups/STM/cavp/gcmtestvectors.zip gcmEncryptExtIV128.rsp
// [Keylen = 128]
// [IVlen = 96]
// [PTlen = 256]
// [AADlen = 128]
// [Taglen = 128]
// Count = 0
// K = 298efa1ccf29cf62ae6824bfc19557fc
// IV = 6f58a93fe1d207fae4ed2f6d
// P = cc38bccd6bc536ad919b1395f5d63801f99f8068d65ca5ac63872daf16b93901
// AAD = 021fafd238463973ffe80256e5b1c6b1
// C = dfce4e9cd291103d7fe4e63351d9e79d3dfd391e3267104658212da96521b7db
// T = 542465ef599316f73a7a560509a2d9f2
///////
const uint8_t K5[] =  {0x29, 0x8e, 0xfa, 0x1c, 0xcf, 0x29, 0xcf, 0x62, 0xae, 0x68, 0x24, 0xbf, 0xc1, 0x95, 0x57, 0xfc};
const uint8_t IV5[] = {0x6f, 0x58, 0xa9, 0x3f, 0xe1, 0xd2, 0x07, 0xfa, 0xe4, 0xed, 0x2f, 0x6d,
						0x00,0x00,0x00,0x01};
const uint8_t P5[] =  {0xcc, 0x38, 0xbc, 0xcd, 0x6b, 0xc5, 0x36, 0xad, 0x91, 0x9b, 0x13, 0x95, 0xf5, 0xd6, 0x38, 0x01, 0xf9, 0x9f, 0x80, 0x68, 0xd6, 0x5c, 0xa5, 0xac, 0x63, 0x87, 0x2d, 0xaf, 0x16, 0xb9, 0x39, 0x01};
const uint8_t A5[] =  {0x02, 0x1f, 0xaf, 0xd2, 0x38, 0x46, 0x39, 0x73, 0xff, 0xe8, 0x02, 0x56, 0xe5, 0xb1, 0xc6, 0xb1};
const uint8_t C5[] =  {0xdf, 0xce, 0x4e, 0x9c, 0xd2, 0x91, 0x10, 0x3d, 0x7f, 0xe4, 0xe6, 0x33, 0x51, 0xd9, 0xe7, 0x9d, 0x3d, 0xfd, 0x39, 0x1e, 0x32, 0x67, 0x10, 0x46, 0x58, 0x21, 0x2d, 0xa9, 0x65, 0x21, 0xb7, 0xdb};
const uint8_t T5[] =  {0x54, 0x24, 0x65, 0xef, 0x59, 0x93, 0x16, 0xf7, 0x3a, 0x7a, 0x56, 0x05, 0x09, 0xa2, 0xd9, 0xf2};



