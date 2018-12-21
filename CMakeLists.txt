cmake_minimum_required(VERSION 3.12)
project(Final_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(GeometricObjects)
include_directories(Headers)

add_executable(Final_Project
        GeometricObjects/CollisionResult.cpp
        GeometricObjects/CollisionResult.h
        GeometricObjects/Polygon.cpp
        GeometricObjects/Polygon.h
        GeometricObjects/Shpere.h
        GeometricObjects/Sphere.cpp
        Headers/CoordinateSystemTranlation.h
        RayTracingElements/Light.h
        MathLibrary/Matrix4D.h
        MathLibrary/Point4D.h
        RayTracingElements/Ray4D.h
        RayTracingElements/RayShooter.h
        RayTracingElements/Scene.h
        MathLibrary/Vector4D.h
        MathLibrary/CoordinateSystemTranslation.cpp
        MathLibrary/Matrix4D.cpp
        MathLibrary/Point4D.cpp
        MathLibrary/Vector4D.cpp
        RayTracingElements/Light.cpp
        RayTracingElements/Ray4D.cpp
        RayTracingElements/RayShooter.cpp
        RayTracingElements/Scene.cpp
        bitmap_image.hpp
        main.cpp RayTracingElements/Node.cpp RayTracingElements/Node.h)
