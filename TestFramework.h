#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <string>


#define TEST(name) \
    void name(); \
    static bool name##_registered = [](){ \
        TestRegistry::instance().add(#name, name); \
        return true; \
    }(); \
    void name()

struct TestCase
{
    std::string name;
    std::function<void()> func;
};

class TestRegistry
{
private:
    std::vector<TestCase> tests;

public:
    static TestRegistry& instance()
    {
        static TestRegistry instance;
        return instance;
    }

    void add(const std::string& name, std::function<void()> func)
    {
        tests.push_back({ name, func });
    }

    void run()
    {
        int passed = 0;
        int failed = 0;

        for (auto& test : tests)
        {
            try
            {
                test.func();
                std::cout << "[PASS] " << test.name << "\n";
                passed++;
            }
            catch (const std::exception& e)
            {
                std::cout << "[FAIL] " << test.name
                    << " - " << e.what() << "\n";
                failed++;
            }
        }

        std::cout << "\n==== RESULTS ====\n";
        std::cout << "Passed: " << passed << "\n";
        std::cout << "Failed: " << failed << "\n";
    }
};
