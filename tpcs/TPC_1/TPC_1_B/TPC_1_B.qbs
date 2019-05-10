import qbs

CppApplication {
    consoleApplication: true
    files: [
        "main.c",
        "memorymanager.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
