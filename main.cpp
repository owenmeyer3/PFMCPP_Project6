/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    T(int v, const char* cp)
    {
        value = v; 
        name = cp;
    }
    int value;
    std::string name;
};

struct S
{
    T* compare(T& a, T& b)
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;

        std::cout << "arguments value properties are equivalent" << std::endl;
        return nullptr;
    }
};

struct U
{
    float length { 2.0f }, width { 2.5f };

    float updateLengthWidthGetArea(float& newLength)
    {

        std::cout << "U's length value: " << this->length << std::endl;
        this->length = newLength;
        std::cout << "U's length updated value: " << this->length << std::endl;
        while( std::abs(this->width - this->length) > 0.001f )
        {
            // make the distance between that->width and that->length get smaller
            this->width += ((this->length - this->width) / std::abs(this->width - this->length)) * 0.001f;
        }
        std::cout << "U's width updated value: " << this->width << std::endl;
        return this->width * this->length;
    }
};

struct W
{
    static float updateLengthWidthGetArea(U& that, float& newLength )
    {
        std::cout << "U's length value: " << that.length << std::endl;
        that.length = newLength;
        std::cout << "U's length updated value: " << that.length << std::endl;
        while( std::abs(that.width - that.length) > 0.001f )
        {
            // make the distance between that->width and that->length get smaller
            that.width += ((that.length - that.width) / std::abs(that.width - that.length)) * 0.001f;
        }
        std::cout << "U's width updated value: " << that.width << std::endl;
        return that.width * that.length;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{

    T t1( 1, "AAAA");
    T t2( 2, "BBBB");
    
    auto f = S{};
    auto smaller = f.compare( t1, t2);
    
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }
    else
    {
        std::cout << "compare arguments values are the same" << std::endl;
    }
    
    U box;
    float updatedValue = 5.f;
    std::cout << "[static func] box's multiplied values: " << W::updateLengthWidthGetArea( box, updatedValue) << std::endl; 
    
    U prism;
    std::cout << "[member func] prism's multiplied values: " << prism.updateLengthWidthGetArea( updatedValue ) << std::endl;
}
