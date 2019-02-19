#include <stdio.h>
#include <protobuf2json.h>

#include "test.pb-c.h"

int main()
{
    char *str;
    SubTest subTest = SUB_TEST__INIT;
    subTest.id = 3;
    Test test = TEST__INIT;
    test.id = 1;
    test.subtest = &subTest;
    test.name = "hello";
    protobuf2json_string(&test.base, (JSON_INDENT(2) | JSON_PRESERVE_ORDER), &str, NULL, 0);
    printf("MessageToJson\n");
    printf("%s\n\n", str);

    ProtobufCMessage *msg = NULL;
    json2protobuf_string(str, 0, &test__descriptor, &msg, NULL, 0);
    if(msg == NULL) {
        printf("json2protobuf_string failed\n");
    }
    else {
        Test *test1 = (Test*)msg;
        printf("JsonToMessage\n");
        printf("test1: id %d, subtest.id %d, name %s\n", test1->id, test1->subtest->id, test1->name);
    }
}