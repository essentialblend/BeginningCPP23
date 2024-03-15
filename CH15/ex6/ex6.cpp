/*Ex 15-6: Start from the Shape and Circle classes we used earlier to introduce abstract classes. Create one more Shape derivative, Rectangle, that has a width and a height. Introduce an extra function called perimeter() that computes a shape’s perimeter. Define a main() program that starts by filling a polymorphic vector<> with a number of Shapes (a hard-coded list of Shapes is fine; there’s no need to generate them randomly). Next, you should print out the total sum of their areas and perimeters, scale all Shapes with a factor 1.5, and then print out these same sums again. of course, you haven’t forgotten what you learned in the first half of this book, so you shouldn’t put all code inside main() itself. Define the appropriate amount of helper functions! 

  Hint: For a circle with radius r, the perimeter (or circumference) is computed using the formula 2πr.*/

import std;

import Point;
import Shape;

void printSums(const std::vector<Shape*>& shapes);
double calculateSumAreas(const std::vector<Shape*>& shapes);
double calculateSumPerimeters(const std::vector<Shape*>& shapes);

int main()
{
    Circle c1{ 1, Point{1, 1} };
    Circle c2{ 2, Point{2, 2} };
    Circle c3{ 3, Point{3, 3} };
    Rectangle r1{ {4, 5}, 4, 5 };
    Rectangle r2{ {6, 7}, 6, 7 };
    Rectangle r3{ {8, 9}, 8, 9 };

    std::vector<Shape*> shapes{ &c1, &r1, &r2, &c2, &c3, &r3 };

    printSums(shapes);

    for (auto* shape : shapes) shape->scaleShape(1.5);

    std::println("");
    printSums(shapes);
}

double calculateSumAreas(const std::vector<Shape*>& shapesArr)
{
    double sum{};
    for (auto* shape : shapesArr)
    {
        sum += shape->computeArea();
    }
    return sum;
}

double calculateSumPerimeters(const std::vector<Shape*>& shapesArr)
{
    double sum{};
    for (auto* shape : shapesArr)
    {
        sum += shape->computePerimeter();
    }
    return sum;
}

void printSums(const std::vector<Shape*>& shapesArr)
{
    std::println("Sum of areas: {:.2f}", calculateSumAreas(shapesArr));
    std::println("Sum of perimeters: {:.2f}", calculateSumPerimeters(shapesArr));
}