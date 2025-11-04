#pragma once

namespace adas
{
    template <typename T> //support generic type
    class Singleton final {
        public:
        static T& Instance(void) noexcept
        {
            static T instance;
            return instance;
        }

        Singleton(const Singleton&) = delete; //delete constructor
        Singleton& operator=(const Singleton&) = delete;

        private:
        Singleton(void) = default;
        ~Singleton(void) = default;
    };
} // namespace adas
