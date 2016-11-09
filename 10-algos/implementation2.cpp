#include "implementation.h"

#include <algorithm>
#include <numeric>
#include <functional>

/*
struct type
{
};

struct variable
{
    struct type * type;
};

struct function
{
    std::vector<variable> arguments;
    type * return_type;
};
*/

//vector<function>, vector<type *>
type * find_return_type(const std::vector<function> & overload_set, std::vector<type *> argument_types)
{

    for (std::vector<function>::const_iterator it = overload_set.begin(); it != overload_set.end(); ++it) // it - aktualnie przegladany function
    {
        bool mismatch = false;

        std::vector<type *>::iterator arg_type_it = argument_types.begin(); // arg_type_it - wskaznik na type
        std::vector<variable>::const_iterator arg_var_it = it->arguments.begin(); // arg_var_it - przechowuje variable
        for (; arg_var_it != it->arguments.end() && arg_type_it != argument_types.end();
            ++arg_var_it, ++arg_type_it)
        {
            if (arg_var_it->type != *arg_type_it)
            {
                mismatch = true;
                break;
            }


        }

        if (mismatch)
        {
            continue;
        }

        if (arg_var_it == it->arguments.end() && arg_type_it == argument_types.end())
        {
            return it->return_type;
        }
    }

    return nullptr;
}

