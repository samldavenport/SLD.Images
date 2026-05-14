#ifndef SLD_IMAGES_INTERNAL_HPP
#define SLD_IMAGES_INTERNAL_HPP

#include "sld-images.hpp"

namespace sld {

    static funcptr_image_memory_alloc _image_memory_alloc = malloc;
    static funcptr_image_memory_free  _image_memory_free  = free; 

    inline void*
    image_memory_alloc(
        const u32 size) {

        return(_image_memory_alloc(size));
    }

    inline void*
    image_memory_free(
        const u32 size) {

        return(_image_memory_free(size));
    }

};

#endif //SLD_IMAGES_INTERNAL_HPP