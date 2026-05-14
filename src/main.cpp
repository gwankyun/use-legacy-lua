#include <iostream>
#include <string>

#include <lua.hpp>

#define CHECK(_cond) \
    if (!(_cond)) \
    { \
        std::cout << "FAIL" << " [" << __LINE__ << "]" << std::endl; \
    }

int main()
{
    lua_State* L = luaL_newstate();
    if (!L)
    {
        return 1;
    }

    luaL_openlibs(L);
    lua_getglobal(L, "_VERSION");

    if (lua_isstring(L, -1))
    {
        std::string version = lua_tostring(L, -1);
        std::cout << version << std::endl;
        CHECK(version == "Lua 5.4");
    }

    lua_Number version = lua_version(L);
    std::cout << version << std::endl;
    CHECK(version == 504);

#ifdef LUA_RELEASE
    std::cout << LUA_RELEASE << std::endl;
    CHECK(std::string(LUA_RELEASE) == "Lua 5.4.8");
#endif // LUA_RELEASE

    lua_close(L);
    return 0;
}
