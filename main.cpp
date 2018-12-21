//
// Created by galax on 9/18/2018.
//




#include "RayTracingElements/Scene.h"
#include <time.h>

int main() {
    clock_t tStart = clock();
    Scene c;
    c.Scan();
    printf("Time taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}






/*
 *
 *     ofstream myfile;
myfile.open("test.txt");
Sphere s1(Point4D(1, 1, 1), 0.5f, 0.75f);
RayShooter f(Point4D(1, 2, 3.5), Point4D(0.0, -1.0, -2.5), Vector4d(0, 1, 0));
Point4D polygonVertex[] = {
        Point4D(0, 0, 0),
        Point4D(0, 0, 2),
        Point4D(2, 0, 2),
        Point4D(0, 1, 0)
};
Polygon po(4, polygonVertex, 0.8f);
for (int i = 0; i < 512; i++) {
    for (int j = 0; j < 512; j++) {
        int s = (int) s1.raySphereIntersection(f.getRay(i, j)).getCollisionDistance();
        int p = (int) po.rayPolygonIntersection(f.getRay(i, j)).getCollisionDistance();
        if (s == NULL && p == NULL)
            myfile << 0;
        else if (s == NULL)
            myfile << p;
        else if (p == NULL)
            myfile << s;
        else if (p > s)
            myfile << s;
        else if (s > p)
            myfile << p;

    }
    myfile << endl;
}
Sphere s1(Point4D(1, 1, 1), 0.5f, 0.75f);
RayShooter f(Point4D(1, 2, 3.5), Point4D(0.0, -1.0, -2.5), Vector4d(0, 1, 0));
cout << endl;
//cout<<s1.raySphereIntersection(f.getRay(50,50));
ofstream myfile;
myfile.open("test.txt");
for (int i = 0; i < 512; i++) {
    for (int j = 0; j < 512; j++) {
        //myfile << (int) s1.raySphereIntersection(f.getRay(i, j)).getCollisionDistance();
    }
    // myfile << endl;
}


f.print();
Point4D p1(0, 1, 0, 0);
Point4D p2(0, 1, 1, 0);
cout << Point4D::pointToPointDistance(p1, p2);

Point4D polygonVertex[] = {
        Point4D(0, 0, 0),
        Point4D(0, 0, 2),
        Point4D(2, 0, 2),
        Point4D(0, 1, 0)
};
Polygon po(4, polygonVertex, 0.8f);
po.print();
cout << endl;
for (int i = 0; i < po.getNumOfVertex(); i++) {
    po.projectPolygonTo2D()[i].print();
}
 */
/*test ray tracing
for (int i = 0; i < 512; i++) {
    for (int j = 0; j < 512; j++) {
        int s = (int) s1.raySphereIntersection(f.getRay(i, j)).getCollisionDistance();
        int p = (int) po.rayPolygonIntersection(f.getRay(i, j)).getCollisionDistance();
        if (s == NULL && p == NULL)
            myfile << 0;
        else if (s == NULL)
            myfile << p;
        else if (p == NULL)
            myfile << s;
        else if (p > s)
            myfile << s;
        else if (s > p)
            myfile << p;

    }
    myfile << endl;
}
 */



/*
   Note: In some of the tests a bitmap image by the name of 'image.bmp'
         is required. If not present the test will fail.
*/
