import qbs

CppApplication {
    consoleApplication: true
    files: [
        "filemanager.h",
        "hexformat.h",
        "main.c",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
