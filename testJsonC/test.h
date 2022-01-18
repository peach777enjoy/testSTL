#pragma once

void test() {
    const char * str = "{}";
    enum json_tokener_error jte;
    struct json_object* jsObjArr = json_tokener_parse_verbose(str, &jte);
}