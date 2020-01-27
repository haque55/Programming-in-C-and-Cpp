
class Box {
    private:
        double height;
        double width;
        double depth;

    public:
        // Constructors
        // Construct Box with all parameters
        Box(double Height, double Width, double Depth);
        // Default Construct Box with no parameters
        Box();
        // Copy constructor
        Box(Box& box);
        // Copy operator
        Box& operator=(const Box& op) = default;

        // Destructor
        ~Box();

        // setter methods
        void setH(double Height);
        void setW(double Width);
        void setD(double Depth);

        // getter methods
        double getH() const;
        double getW() const;
        double getD() const;
};