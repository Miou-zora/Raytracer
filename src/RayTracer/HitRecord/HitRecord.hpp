/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** HitRecord
*/

#pragma once

#include "Vertex.hpp"
#include "Vector.hpp"
#include "Material.hpp"
#include <memory>

namespace RayTracer {
    class HitRecord {
        public:
            HitRecord(void) = default;
            virtual ~HitRecord() = default;

            Maths::Vertex getIntersectionPoint() const { return _intersection_point; };
            Maths::Vector getNormal() const { return _normal; };
            const RayTracer::Material &getMaterial() const { return _material; };
            bool isFrontFace() const { return _front_face; };
            bool isHit() const { return _hit; };

            void setIntersectionPoint(const Maths::Vertex &intersection_point) { this->_intersection_point = intersection_point; };
            void setNormal(const Maths::Vector &normal) { this->_normal = normal; };
            void setMaterial(const RayTracer::Material &material) { this->_material = material; };
            void setFrontFace(bool front_face) { this->_front_face = front_face; };
            void setHit(bool hit) { this->_hit = hit; };

        private:
            Maths::Vertex _intersection_point;
            Maths::Vector _normal;
            RayTracer::Material _material;
            bool _front_face;
            bool _hit;
    };
}
