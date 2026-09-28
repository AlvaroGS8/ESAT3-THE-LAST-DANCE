


enum class Actions{
    Shoot
};

class Input {
public:
    bool isButtonDown(Actions a) const;
    bool isButtonUp(Actions a) const;
    bool isButtonPressed(Actions a) const;
    bool isButtonReleased(Actions a) const;

    mapKeyToAction(Actions a, ???);

};

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