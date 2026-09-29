#include <unordered_map>
#include <string>


class Input {

    std::unordered_map<std::string, char> InputMap;

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
    bool isButtonDown(std::string action) const;
    bool isButtonUp(std::string action) const;
    bool isButtonPressed(std::string action) const;
    bool isButtonReleased(std::string action) const;

    float getFloatValue(std::string action) const;
    int getIntValue(std::string action) const;

    // Keyboard system
    bool isButtonDown(Keys key) const;
    bool isButtonUp(Keys key) const;
    bool isButtonPressed(Keys key) const;
    bool isButtonReleased(Keys key) const;

    // Feature functions
    void mapKeyToAction(std::string action, const char key);
    void addActionAndKey(std::string action, const char key);
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
        //raton -> [int, int]

        if (i_.IsButtonPressed(Actions::Shoot)){
            Disparar(cabeza, pistola);
        }

    }
}