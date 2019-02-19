# Test for protobuf2json-c

## Requirement:
* protobuf-c
* protobuf2json-c[https://github.com/Sannis/protobuf2json-c]

## Test Result:

```
MessageToJson
{
  "id": 1,
  "subTest": {
    "id": 3
  },
  "name": "hello"
}

JsonToMessage
test1: id 1, subtest.id 3, name hello
```