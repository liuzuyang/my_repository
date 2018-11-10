import qbs
Project {
    minimumQbsVersion: "1.7.1"
    CppApplication {
        consoleApplication: true
        files: [
            "main.cpp",
            "string.h",
            "strvec.h",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}