// testConsole.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <Windows.h>
#include <boost/filesystem.hpp>

int main(int argc, char* argv[])
{
  auto path = boost::filesystem::current_path();
  path /= "testConsole.exe";

  SIZE_T attribute_list_size = 0;
  BOOL status = InitializeProcThreadAttributeList(nullptr, 1, 0, &attribute_list_size);

  PPROC_THREAD_ATTRIBUTE_LIST attribute_list = (PPROC_THREAD_ATTRIBUTE_LIST)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, attribute_list_size);

  status = InitializeProcThreadAttributeList(attribute_list, 1, 0, &attribute_list_size);

  auto value = PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON;
  status = UpdateProcThreadAttribute(attribute_list, 0, PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY, &value, sizeof(value), nullptr, nullptr);

  PROCESS_INFORMATION pi{};
  STARTUPINFOEX si;
  ZeroMemory(&si.StartupInfo, sizeof(si.StartupInfo));
  si.StartupInfo.cb = sizeof(STARTUPINFO);
  si.lpAttributeList = attribute_list;

  CreateProcess(
    NULL,
    (LPSTR)path.string().c_str(),
    NULL,
    NULL,
    FALSE,
    EXTENDED_STARTUPINFO_PRESENT,
    NULL,
    NULL,
    &si.StartupInfo,
    &pi);
}