
#ifndef __SHAPE_H
#define __SHAPE_H
#include <string>

using namespace std;
namespace Drawing {
    class Shape{

        protected:
            int thickness;
            string color;
    
        public:
                Shape();
                Shape(int t, string c);
                void display();
    };
}
#endif


