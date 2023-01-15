#include "CParser.h"
#include <stdexcept>
#include <ctype.h>

// To keep this simple, input will be name:value.
void CParser::Usage()
{
    printf("Usage:\n");
    printf("ErrorSimulator [/return:N] [/stream:(stdout)|(stderr)]\n");
}

void CParser::Parse()
{
    if (1 == m_nArgs)
    {
        // Expecting the path to ErrorSimulator.exe as first argument.
        // This is valid but mostly pointless. Write to stdout and return 0.
        return;
    }

    if (m_nArgs > 3)
    {
        Usage();
        throw std::invalid_argument("");
    }

    for (int x = 1; x < m_nArgs; x++)
    {
        if (0 == _strnicmp(m_pArgs[x], "/return:", 8))
        {
            const char* pNum = &m_pArgs[x][8];
            int y = 0;
            if (NULL == pNum[y])
            {
                Usage();
                printf("Return number required.\n");
                throw std::invalid_argument("Return number required.");
            }
            do {
                if (!isdigit(pNum[y]))
                {
                    Usage();
                    printf("Must return a number.\n");
                    throw std::invalid_argument("Must return a number.");
                }

                y++;
            } while (NULL != pNum[y]);
            m_Return = atoi(&m_pArgs[x][8]);
        }
        else if (0 == _strnicmp(m_pArgs[x], "/stream:", 8))
        {
            const char* pStream = &m_pArgs[x][8];
            if (6 != strlen(pStream))
            {
                Usage();
                printf("Stream must be stdout or stderr.\n);");
                throw std::invalid_argument("Stream must be stdout or stderr.");
            }

            if (0 == _strnicmp(pStream, "stdout", 6))
            {
                m_OutStream = stdout;
            }
            else if (0 == _strnicmp(pStream, "stderr", 6))
            {
                m_OutStream = stderr;
            }
            else
            {
                Usage();
                printf("Stream must be stdout or stderr.\n);");
                throw std::invalid_argument("Stream must be stdout or stderr.");
            }
        }
        else
        {
            Usage();
            throw std::invalid_argument("");
        }
    }
}

