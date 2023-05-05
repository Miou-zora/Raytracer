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

            const Maths::Vertex &getIntersectionPoint() const { return _intersection_point; };
            const Maths::Vector &getNormal() const { return _normal; };
            const RayTracer::Material &getMaterial() const { return _material; };
            bool isFrontFace() const { return _frontFace; };
            bool isHit() const { return _hit; };
            double getDistance() const { return _distance; };

            void setIntersectionPoint(const Maths::Vertex &intersection_point) { this->_intersection_point = intersection_point; };
            void setNormal(const Maths::Vector &normal) { this->_normal = normal; };
            void setMaterial(const RayTracer::Material &material) { this->_material = material; };
            void setFrontFace(bool frontFace) { this->_frontFace = frontFace; };
            void setHit(bool hit) { this->_hit = hit; };
            void setDistance(double distance) { this->_distance = distance; };

        private:
            Maths::Vertex _intersection_point;
            Maths::Vector _normal;
            RayTracer::Material _material;
            bool _frontFace;
            bool _hit;
            double _distance;
    };
}
