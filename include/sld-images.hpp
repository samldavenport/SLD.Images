#ifndef SLD_IMAGES_HPP
#define SLD_IMAGES_HPP

#include "sld.hpp"

#ifdef SLD_IMAGE_STATIC
#   define SLD_IMAGE_API
#elif defined(SLD_DLL_EXPORT)
#   define SLD_IMAGE_API __declspec(dllexport)
#else
#   define SLD_IMAGE_API __declspec(dllimport)
#endif


namespace sld {

    //--------------------------------------------------------------------
    // PRIMITIVE TYPES
    //--------------------------------------------------------------------

    typedef u32  image_format;
    typedef void image_pixel;

    //--------------------------------------------------------------------
    // STRUCTURED TYPES
    //--------------------------------------------------------------------

    struct jpeg_context;
    struct png_context;
    struct bmp_context;
    struct image_data;
    struct image_metadata;
    struct image_pixel_rgba;
    struct image_pixel_argb;
    struct image_pixel_gbra;
    struct image_pixel_agbr;
    struct image_pixel_rgb;
    struct image_pixel_bgr;

    //--------------------------------------------------------------------
    // FUNCTION POINTERS
    //--------------------------------------------------------------------

    typedef void* (funcptr_image_memory_alloc*) (const u32   size);
    typedef void  (funcptr_image_memory_free*)  (const void* memory);

    //--------------------------------------------------------------------
    // MEMORY MANAGEMENT
    //--------------------------------------------------------------------

    SLD_IMAGE_API void
    image_set_memory_methods(
        const funcptr_image_memory_alloc alloc,
        const funcptr_image_memory_free  free
    );

    //--------------------------------------------------------------------
    // IMAGE DATA
    //--------------------------------------------------------------------

    SLD_IMAGE_API image_pixel_rgba* image_pixels_rgba       (const image_data* img);
    SLD_IMAGE_API image_pixel_argb* image_pixels_argb       (const image_data* img);
    SLD_IMAGE_API image_pixel_gbra* image_pixels_gbra       (const image_data* img);
    SLD_IMAGE_API image_pixel_agbr* image_pixels_agbr       (const image_data* img);
    SLD_IMAGE_API image_pixel_rgb*  image_pixels_rgb        (const image_data* img);
    SLD_IMAGE_API image_pixel_bgr*  image_pixels_bgr        (const image_data* img);

    //--------------------------------------------------------------------
    // JPEG
    //--------------------------------------------------------------------

    SLD_IMAGE_API u32               jpeg_context_memory_requriement (const void* jpeg_data_ptr, const u32 jpeg_data_size);
    SLD_IMAGE_API jpeg_context*     jpeg_context_create             (const void* jpeg_data_ptr, const u32 jpeg_data_size);
    SLD_IMAGE_API jpeg_context*     jpeg_context_memory_init        (const void* jpeg_data_ptr, const u32 jpeg_data_size, const u32 mem_size, void* mem_ptr);
    SLD_IMAGE_API void              jpeg_context_assert_valid       (const jpeg_context* jpeg);
    SLD_IMAGE_API void              jpeg_context_destroy            (const jpeg_context* jpeg);
    SLD_IMAGE_API const image_data* jpeg_context_image_data         (const jpeg_context* jpeg);

    //--------------------------------------------------------------------
    // PNG
    //--------------------------------------------------------------------

    SLD_IMAGE_API u32               png_context_memory_requriement (const void* png_data_ptr, const u32 png_data_size);
    SLD_IMAGE_API png_context*      png_context_create             (const void* png_data_ptr, const u32 png_data_size);
    SLD_IMAGE_API png_context*      png_context_memory_init        (const void* png_data_ptr, const u32 png_data_size, const u32 mem_size, void* mem_ptr);
    SLD_IMAGE_API void              png_context_assert_valid       (const png_context* png);
    SLD_IMAGE_API void              png_context_destroy            (const png_context* png);
    SLD_IMAGE_API const image_data* png_context_image_data         (const png_context* png);

    //--------------------------------------------------------------------
    // BMP
    //--------------------------------------------------------------------

    SLD_IMAGE_API u32               bmp_context_memory_requriement (const void* bmp_data_ptr, const u32 bmp_data_size);
    SLD_IMAGE_API bmp_context*      bmp_context_create             (const void* bmp_data_ptr, const u32 bmp_data_size);
    SLD_IMAGE_API bmp_context*      bmp_context_memory_init        (const void* bmp_data_ptr, const u32 bmp_data_size, const u32 mem_size, void* mem_ptr);
    SLD_IMAGE_API void              bmp_context_assert_valid       (const bmp_context* bmp);
    SLD_IMAGE_API void              bmp_context_destroy            (const bmp_context* bmp);
    SLD_IMAGE_API const image_data* bmp_context_image_data         (const bmp_context* bmp);
    
    //--------------------------------------------------------------------
    // DEFINITIONS
    //--------------------------------------------------------------------

    struct image_data {
        image_pixel*    pixel_array;        
        image_metadata* metadata;
        image_format    format;
        u32             channel_count;
        u32             width;
        u32             height;
    };

    struct image_pixel_rgba {
        union {
            struct {
                byte r;
                byte g;
                byte b;
                byte a;
            };
            u32 hex;
        }
    };

    struct image_pixel_argb {
        union {
            struct {
                byte r;
                byte g;
                byte b;
                byte a;
            };
            u32 hex;
        }
    };

    struct image_pixel_gbra {
        union {
            struct {
                byte r;
                byte g;
                byte b;
                byte a;
            };
            u32 hex;
        }
    };

    struct image_pixel_agbr {
        union {
            struct {
                byte r;
                byte g;
                byte b;
                byte a;
            };
            u32 hex;
        }
    };



    //--------------------------------------------------------------------
    // ENUMS
    //--------------------------------------------------------------------

    enum image_format_e {
        image_format_e_rgba = 0,
        image_format_e_argb = 1,
        image_format_e_abgr = 2,
        image_format_e_bgra = 3
    };

};

#endif //SLD_IMAGES_HPP