// laba3.2kurs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>



class Shape
{
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
    virtual std::string GetName() = 0;
};

class Shape2D:public Shape
{
protected:
    float area = 0;
    virtual void CalculateArea() = 0;
public:
    float GetArea()
    {
       CalculateArea();
       return area;
    }

    bool operator> (Shape2D* shape) {
        return area > shape->GetArea(); // a->f = *(&(a)).f
    }

    bool operator< (Shape2D* shape) {
        return !(area > shape->GetArea());
    }

    bool operator== (Shape2D* shape) {
        return area == shape->area;
    }


};

class Square: public Shape2D
{
private:
    float side;
    void CalculateArea()override
    {
        area = side* side;
    }
public:
    void Scale(float scaleFactor) override
    {
        side*= scaleFactor;
    }
    void ShowInfo()override
    {
        std::cout << GetName() << std::endl << "My area is =  " << area << "\n" << "My side is: " << side << "\n";
    }
    std::string GetName()override
    {
        return "I'm Alexander";
    }


    Square(float side)
        {
        this->side = side;
        }

};

class Triangle : public Shape2D
{
private:
    float base, height;
    void CalculateArea()override
    {
        area = base* height / 2;
    }
public:
    void Scale(float scaleFactor) override
    {
        base*= scaleFactor, height*= scaleFactor;
    }
    void ShowInfo()override
    {
        std::cout << GetName() << std::endl << "My area is =  " << area << "\n" << "My base is: " << base << "\n" << "My height is: " << height << "\n";
    }
    std::string GetName()override
    {
        return "i'm Vladimir";
    }

    Triangle(float base, float height)
    {
        this->base = base;
        this->height = height;
    }

};

class Circle : public Shape2D
{
private:
    float radius;
    void CalculateArea()override
    {
        3.1415 * radius * radius;
    }
public:
    void Scale(float scaleFactor)override
    {
        radius *= scaleFactor;
    }
    void ShowInfo()override
    {
        std::cout << GetName() << std::endl << "My area is =  " << area << "\n" << "My radius is: " << radius << "\n";
    }
    std::string GetName()override
    {
        return "i'm Yaroslav";
    }

    Circle(float radius)
    {
        this->radius = radius;
    }

};

class Shape3D: public Shape
{
protected:
    float volume = 0;
    virtual void CalculateVolume() = 0;
public:
    float GetVolume()
    {
        CalculateVolume();
        return volume;
    }

    bool operator> (Shape3D* shape) {
        return volume > shape->volume;
    }

    bool operator< (Shape3D* shape) {
        return !(volume > shape->volume);
    }

    bool operator== (Shape3D* shape) {
        return volume == shape->volume;
    }


};

class  TriangularPyramid : public Shape3D
{
private:
    Triangle *Olegovich;
    float height;
    void CalculateVolume()override
    {
        volume = Olegovich->GetArea() * height / 3;
    }
public:
    void Scale(float scaleFactor) override
    {
        Olegovich->Scale(scaleFactor); height *= scaleFactor;
    }
    void ShowInfo()override
    {
        std::cout << GetName() << std::endl << "My volume is =  " << volume << "\n" << "Area of my Triangle is:  " << Olegovich->GetArea() << "\n" << "My height is: " << height << "\n";
    }
    std::string GetName()override
    {
        return "i'm Olegovich";
    }

    TriangularPyramid (Triangle *Olegovich, float height)
    {
       this->Olegovich = Olegovich;
       this->height = height;
    }

};
class  Cylinder : public Shape3D
{
private:
    Circle* Mihail;
    float height;
    void CalculateVolume()override
    {
        volume = Mihail->GetArea()* height;
    }
public:
    void Scale(float scaleFactor) override
    {
        Mihail->Scale(scaleFactor); height *= scaleFactor;
    }
    void ShowInfo()override
    {
        std::cout << GetName() << std::endl << "My volume is =  " << volume << "\n" << "Area of my Circle is:  " << Mihail->GetArea() << "\n" << "My height is: " << height << "\n";
    }
    std::string GetName()override
    {
        return "i'm Mihail";
    }

    Cylinder(Circle* Mihail, float height)
    {
        this->Mihail = Mihail;
        this->height = height;
    }

};

class  Sphere : public Shape3D
{
private:
    float radius;
    void CalculateVolume()override
    {
        volume = radius * 3.1415*radius*radius*4/3;
    }
public:
    void Scale(float scaleFactor) override
    {
        radius *= scaleFactor;
    }
    void ShowInfo()override
    {
        std::cout << GetName() << std::endl << "My volume is =  " << volume << "\n" << "My radius is: " << radius << "\n";
    }
    std::string GetName()override
    {
        return "i'm Sphera";
    }

    Sphere (float radius)
    {
        this->radius = radius;
    }

};
int main()
{
    Square F(3);
    F.ShowInfo();

    Triangle triangle(3.2, 4);
    triangle.ShowInfo();
    std::cout << std::endl;
    triangle.Scale(5);
    triangle.ShowInfo();
    std::cout << std::endl;

    Circle circle(5.5);
    circle.ShowInfo();
    std::cout << std::endl;
    circle.Scale(5);
    circle.ShowInfo();
    std::cout << std::endl;

    Square square(7.5);
    square.ShowInfo();
    std::cout << std::endl;
    square.Scale(5);
    square.ShowInfo();
    std::cout << std::endl;

    TriangularPyramid piramid(&triangle, 14);
    piramid.ShowInfo();
    std::cout << std::endl;
    piramid.Scale(1.5);
    piramid.ShowInfo();
    std::cout << std::endl;
    triangle.Scale(0.67);
    piramid.ShowInfo();
    std::cout << std::endl;

    Cylinder cylinder(&circle, 8);
    cylinder.ShowInfo();
    std::cout << std::endl;
    cylinder.Scale(1.5);
    cylinder.ShowInfo();
    std::cout << std::endl;
    circle.Scale(0.67);
    cylinder.ShowInfo();
    std::cout << std::endl;

    Sphere sphere(4.9);
    sphere.ShowInfo();
    std::cout << std::endl;
    sphere.Scale(1.5);
    sphere.ShowInfo();
    std::cout << std::endl;

    if (circle > &triangle) std::cout << "проверка оператора >" << std::endl;
    if (triangle < &circle) std::cout << "проверка оператора <" << std::endl;
    if (!(circle == &triangle)) std::cout << "проверка оператора ==" << std::endl;

    if (cylinder > &piramid) std::cout << "проверка оператора >" << std::endl;
    if (piramid < &cylinder) std::cout << "проверка оператора <" << std::endl;
    if (!(cylinder == &piramid)) std::cout << "проверка оператора ==" << std::endl;

}
