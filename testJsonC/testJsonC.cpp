// testJsonC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "json.h"
#include "test.h"
#include <iostream>

#define USING_NAMESPACE(x) using namespace x;

USING_NAMESPACE(std)

void test(int id, const char* pszMethod, const char* pszParams)
{
    struct json_object* jsObj = json_object_new_object();
    json_object_object_add(jsObj, "id", json_object_new_int(id));
    json_object_object_add(jsObj, "jsonrpc", json_object_new_string("2.0"));
    json_object_object_add(jsObj, "method", json_object_new_string(pszMethod));

    if (NULL != pszParams)
    {
        enum json_tokener_error jte;
        struct json_object* jsParams = json_tokener_parse_verbose(pszParams, &jte);
        if (NULL == jsParams)
        {
            printf("%s", json_tokener_error_desc(jte));
        }
        else
        {
            json_object_object_add(jsObj, "params", jsParams);
        }
    }

    /*convert to json string*/
    const char* pszJson = json_object_to_json_string_ext(jsObj, JSON_C_TO_STRING_PLAIN);

    /*websocket request*/
    //WsRequest(pszJson);

    /*free json object*/
    json_object_put(jsObj);

    return;
}

int main()
{
    struct json_tokener *tok;
    struct json_object *my_string, *my_int, *my_object, *my_array;
    struct json_object *new_obj;
    int i;
    int bar = 13;

    my_string = json_object_new_string("\t");
    printf("my_string = %s\n", json_object_get_string(my_string));
    printf("my string.to_string()=%s\n",json_object_to_json_string(my_string));
    json_object_put(my_string);
    
    my_string = json_object_new_string("\\");
    printf("my_string = %s\n", json_object_get_string(my_string));
    printf("my_string.to_string()=%s\n", json_object_to_json_string(my_string));
    json_object_put(my_string);

    my_string = json_object_new_string("foo");
    printf("my_string = %s\n", json_object_get_string(my_string));
    printf("my_string.to_string()=%s\n", json_object_to_json_string(my_string));
    json_object_put(my_string);


    my_int = json_object_new_int(9);
    printf("my_int = %d\n", json_object_get_int(my_int));
    printf("my_int.to_string()=%s\n", json_object_to_json_string(my_int));

    my_array = json_object_new_array();

    json_object_array_add(my_array, json_object_new_int(1));
    json_object_array_add(my_array, json_object_new_int(2));
    json_object_array_add(my_array, json_object_new_int(3));
    json_object_array_put_idx(my_array, 4, json_object_new_int(5));
    printf("my_array=\n");
   
    for (i = 0; i < json_object_array_length(my_array); i++) {
        struct json_object *obj = json_object_array_get_idx(my_array, i);
        printf("\t[%d]=%s\n", i, json_object_to_json_string(obj));
    }
    printf("my_array.to_string()=%s\n", json_object_to_json_string(my_array));

    my_object = json_object_new_object();

    json_object_object_add(my_object, "adc", json_object_new_int(12));
    json_object_object_add(my_object, "foo", json_object_new_int(bar));
    json_object_object_add(my_object, "bool0", json_object_new_boolean(0));
    json_object_object_add(my_object, "bool1", json_object_new_boolean(1));
    json_object_object_add(my_object, "baz", json_object_new_string("bang"));
    //      json_object_object_del(my_object,"baz");


    printf("my_object=\n");
    json_object_object_foreach(my_object, key, val) {
        printf("\t%s:%s\n", key, json_object_to_json_string(val));
    }
    printf("my_object.to_string()=%s\n", json_object_to_json_string(my_object));

    
    cout << "End!\n";
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
