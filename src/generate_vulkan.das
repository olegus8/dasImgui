require daslib/cpp_gen

[export]
def main

    // configure

    blocked_functions <- [{auto[]
        "operator delete";
        "operator new";
        "__security_init_cookie";
        "__security_check_cookie"
    }]

    // generate

    var args <- get_command_line_arguments()
    bindHeaders(args[3], args[4])
