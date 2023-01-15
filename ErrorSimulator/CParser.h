#pragma once
#include <stdio.h>

class CParser
{
private:
    const int m_nArgs;
    const char** m_pArgs;
    int m_Return;  // Vaue to return
    FILE* m_OutStream;

public:
    CParser(int argc, char* argv[]) : m_nArgs(argc), m_pArgs(const_cast<const char **>(argv)),
        m_Return(0), m_OutStream(stdout) {}
    void Parse();

    FILE* GetStream() { return m_OutStream; }
    int GetReturn() { return m_Return; }

protected:
    void Usage();
};

