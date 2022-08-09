

struct ISample
{
public:
    virtual std::string Name() const = nullptr;
};

class WindowsSample : public ISample
{
    virtual std::string Name() const override {
        return "windows";
    }
};

class LinuxSample : public ISample
{
    virtual std::string Name() const override {
        return "linux";
    }
};

class Sample : public ISample
{
private:
    std::unique_ptr<ISample> m_sample;
    Sample() 
    {
#ifdef _WIN32
        m_sample = std::make_unique<WindowsSample>();
#else
        m_sample = std::make_unique<LinuxSample>();
#endif 
    }
    virtual ~Sample() = default;

    virtual std::string Name() const override {
        return m_sample->Name();
    }
};
