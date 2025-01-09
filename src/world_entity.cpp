#include "world_entity.h"


World_entity::World_entity(bool is_static)
    : World_entity(
        is_static,
        vec3{ 0.0f, 0.0f, 0.0f },
        versor{ 0.0f, 0.0f, 0.0f, 1.0f },
        vec3{ 1.0f, 1.0f, 1.0f })
{
}

World_entity::World_entity(
    bool is_static,
    vec3 position,
    versor rotation,
    vec3 scale)
    : m_is_static(is_static)
    , m_guid(GUID::generate())
{
    set_position(position);
    set_rotation(rotation);
    set_scale(scale);
}
