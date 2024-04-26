#ifndef NV_FFI_H
#define NV_FFI_H

#include "../common/callback.h"
#include <stdbool.h>

int nv_encode_driver_support();

int nv_decode_driver_support();

void *nv_new_encoder(void *handle, int64_t luid, int32_t api,
                     int32_t dataFormat, int32_t width, int32_t height,
                     int32_t bitrate, int32_t framerate, int32_t gop);

int nv_encode(void *encoder, void *tex, EncodeCallback callback, void *obj);

int nv_destroy_encoder(void *encoder);

void *nv_new_decoder(void *device, int64_t luid, int32_t api, int32_t codecID);

int nv_decode(void *decoder, uint8_t *data, int len, DecodeCallback callback,
              void *obj);

int nv_destroy_decoder(void *decoder);

int nv_test_encode(void *outDescs, int32_t maxDescNum, int32_t *outDescNum,
                   int32_t api, int32_t dataFormat, int32_t width,
                   int32_t height, int32_t kbs, int32_t framerate, int32_t gop);

int nv_test_decode(void *outDescs, int32_t maxDescNum, int32_t *outDescNum,
                   int32_t api, int32_t dataFormat, uint8_t *data,
                   int32_t length);

int nv_set_bitrate(void *encoder, int32_t kbs);

int nv_set_framerate(void *encoder, int32_t framerate);

#endif // NV_FFI_H