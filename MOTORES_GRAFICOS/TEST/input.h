#include <unordered_map>
#include <string>

struct vec2{
    float x,y;
}

struct vec2i{
    int x,y;
}

class Input {

    std::unordered_map<noString, char> InputMap;

    enum class Keys{
        kKey_A = 97,
        kKey_B,
        kKey_D,
        kKey_E,
        kKey_F,
        kKey_RightButtonClick,
    }
                
public:

    // Action system
    bool isButtonDown(noString action) const;
    bool isButtonUp(noString action) const;
    bool isButtonPressed(noString action) const;
    bool isButtonReleased(noString action) const;

    float getFloatValue(noString action) const;
    vec2 getStickValue(noString action) const;
    vec2i getMousePosition() const;
    int getIntValue(noString action) const;

    // Keyboard system
    bool isButtonDown(Keys key) const;
    bool isButtonUp(Keys key) const;
    bool isButtonPressed(Keys key) const;
    bool isButtonReleased(Keys key) const;

    // Feature functions
    void mapKeyToAction(noString action, const char key);
    void addActionAndKey(noString action, const char key);
};

/*
Class Game{

    Input *i_;

    void Init(){
        i_ = engine.getInput();
    }

    void Loop(float delta){
        //Key -> bool
        //Gatillo -> float
        //Rueda -> int
        //Joystick -> [float, float]
        //raton -> Mejor tratar como botón la rueda. 

        if (i_.IsButtonPressed(Actions::Shoot)){
            Disparar(cabeza, pistola);
        }

    }
}