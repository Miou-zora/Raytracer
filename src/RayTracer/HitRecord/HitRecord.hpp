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

class HitRecord {
    public:
        HitRecord(void);
        ~HitRecord();

        Maths::Vertex getIntersectionPoint() const { return intersection_point; };
        Maths::Vector getNormal() const { return normal; };
        std::shared_ptr<RayTracer::Material> getMaterial() const { return material; };
        bool isFrontFace() const { return front_face; };

        void setIntersectionPoint(const Maths::Vertex &intersection_point) { this->intersection_point = intersection_point; };
        void setNormal(const Maths::Vector &normal) { this->normal = normal; };
        void setMaterial(const std::shared_ptr<RayTracer::Material> &material) { this->material = material; };
        void setFrontFace(bool front_face) { this->front_face = front_face; };

    private:
        Maths::Vertex intersection_point;
        Maths::Vector normal;
        std::shared_ptr<RayTracer::Material> material;
        bool front_face;
};
