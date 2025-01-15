#pragma once

#include <cglm/cglm.h>
#include "guid.h"


// Basic form of a placable object in the world.
class World_entity
{
public:
    World_entity(bool is_static);
    World_entity(bool is_static,
                 vec3 position,
                 versor rotation,
                 vec3 scale);

    inline void set_position(vec3 position)
    {
        glm_vec3_copy(position, m_position);
    }

    inline void set_rotation(versor rotation)
    {
        glm_quat_copy(rotation, m_rotation);
    }

    inline void set_scale(vec3 scale)
    {
        glm_vec3_copy(scale, m_scale);
    }

    inline void get_position(vec3& out_position)
    {
        glm_vec3_copy(m_position, out_position);
    }

    inline void get_rotation(versor& out_rotation)
    {
        glm_quat_copy(m_rotation, out_rotation);
    }

    inline void get_scale(vec3& out_scale)
    {
        glm_vec3_copy(m_scale, out_scale);
    }

private:
    bool   m_is_static;
    vec3   m_position;
    versor m_rotation;
    vec3   m_scale;
    GUID   m_guid;
};
