// JSArray\init.h

#ifndef INIT_H
#define INIT_H

// Used to Initialize the application and run the gui.
public ref class Initializer
{
public:
    // Makes the call to init();
    Initializer(void);

protected:
    virtual ~Initializer();

private:
    System::Windows::Forms::ApplicationContext^ jsarray_context;
    // Uses the ApplicationContext class and runs the applications gui.
    void init();

};

#endif // INIT_H
