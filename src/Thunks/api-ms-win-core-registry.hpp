
namespace YY
{
	namespace Thunks
	{

#if (YY_Thunks_Support_Version < NTDDI_WS03SP1)
//Windows XP Professional x64 Edition, Windows Server 2003 with SP1

EXTERN_C
LSTATUS
APIENTRY
RegDeleteKeyExW(
	_In_ HKEY hKey,
	_In_ LPCWSTR lpSubKey,
	_In_ REGSAM samDesired,
	_Reserved_ DWORD Reserved
	)
#ifdef YY_Thunks_Defined
	;
#else
{
	if(auto const pRegDeleteKeyExW = try_get_RegDeleteKeyExW())
	{
		return pRegDeleteKeyExW(hKey, lpSubKey, samDesired, Reserved);
	}


	return RegDeleteKeyW(hKey, lpSubKey);
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegDeleteKeyExW, 16);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WS03SP1)
//Windows XP Professional x64 Edition, Windows Server 2003 with SP1

EXTERN_C
LSTATUS
APIENTRY
RegDeleteKeyExA(
	_In_ HKEY hKey,
	_In_ LPCSTR lpSubKey,
	_In_ REGSAM samDesired,
	_Reserved_ DWORD Reserved
	)
#ifdef YY_Thunks_Defined
	;
#else
{
	if (auto const pRegDeleteKeyExA = try_get_RegDeleteKeyExA())
	{
		return pRegDeleteKeyExA(hKey, lpSubKey, samDesired, Reserved);
	}

	return RegDeleteKeyA(hKey, lpSubKey);
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegDeleteKeyExA, 16);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WIN6)
//Windows Vista, Windows Server 2008

EXTERN_C
LSTATUS
APIENTRY
RegSetKeyValueW(
	_In_ HKEY hKey,
	_In_opt_ LPCWSTR lpSubKey,
	_In_opt_ LPCWSTR lpValueName,
	_In_ DWORD dwType,
	_In_reads_bytes_opt_(cbData) LPCVOID lpData,
	_In_ DWORD cbData
	)
#ifdef YY_Thunks_Defined
	;
#else
{
	//Empty?
	if (lpSubKey == nullptr || *lpSubKey == L'\0')
	{
		return RegSetValueExW(hKey, lpValueName, 0, dwType, (const BYTE*)lpData, cbData);
	}
	else
	{
		HKEY hSubKey;
		auto lStatus = RegCreateKeyExW(hKey, lpSubKey, 0, nullptr, 0, KEY_SET_VALUE, nullptr, &hSubKey, nullptr);

		if (lStatus == ERROR_SUCCESS)
		{
			lStatus = RegSetValueExW(hSubKey, lpValueName, 0, dwType, (const BYTE*)lpData, cbData);

			RegCloseKey(hSubKey);
		}

		return lStatus;
	}
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegSetKeyValueW, 24);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WIN6)
//Windows Vista, Windows Server 2008

EXTERN_C
LSTATUS
APIENTRY
RegSetKeyValueA(
	_In_ HKEY hKey,
	_In_opt_ LPCSTR lpSubKey,
	_In_opt_ LPCSTR lpValueName,
	_In_ DWORD dwType,
	_In_reads_bytes_opt_(cbData) LPCVOID lpData,
	_In_ DWORD cbData
	)
#ifdef YY_Thunks_Defined
	;
#else
{
	//Empty?
	if (lpSubKey == nullptr || *lpSubKey == '\0')
	{
		return RegSetValueExA(hKey, lpValueName, 0, dwType, (const BYTE*)lpData, cbData);
	}
	else
	{
		HKEY hSubKey;
		auto lStatus = RegCreateKeyExA(hKey, lpSubKey, 0, nullptr, 0, KEY_SET_VALUE, nullptr, &hSubKey, nullptr);

		if (lStatus == ERROR_SUCCESS)
		{
			lStatus = RegSetValueExA(hSubKey, lpValueName, 0, dwType, (const BYTE*)lpData, cbData);

			RegCloseKey(hSubKey);
		}

		return lStatus;
	}
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegSetKeyValueA, 24);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WIN6)
//Windows Vista, Windows Server 2008

EXTERN_C
LSTATUS
APIENTRY
RegDeleteKeyValueW(
    _In_ HKEY hKey,
    _In_opt_ LPCWSTR lpSubKey,
    _In_opt_ LPCWSTR lpValueName
    )
#ifdef YY_Thunks_Defined
	;
#else
{
	HKEY hSubKey;
	auto lStatus = RegOpenKeyExW(hKey, lpSubKey, 0, KEY_SET_VALUE, &hSubKey);

	if (lStatus == ERROR_SUCCESS)
	{
		lStatus = RegDeleteValueW(hSubKey, lpValueName);
		RegCloseKey(hSubKey);
	}

	return lStatus;
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegDeleteKeyValueW, 12);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WIN6)
//Windows Vista, Windows Server 2008

EXTERN_C
LSTATUS
APIENTRY
RegDeleteKeyValueA(
	_In_ HKEY hKey,
	_In_opt_ LPCSTR lpSubKey,
	_In_opt_ LPCSTR lpValueName
	)
#ifdef YY_Thunks_Defined
	;
#else
{
	HKEY hSubKey;
	auto lStatus = RegOpenKeyExA(hKey, lpSubKey, 0, KEY_SET_VALUE, &hSubKey);

	if (lStatus == ERROR_SUCCESS)
	{
		lStatus = RegDeleteValueA(hSubKey, lpValueName);
		RegCloseKey(hSubKey);
	}

	return lStatus;
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegDeleteKeyValueA, 12);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WIN6)
//Windows Vista, Windows Server 2008

EXTERN_C
LSTATUS
APIENTRY
RegDeleteTreeW(
	_In_ HKEY hKey,
	_In_opt_ LPCWSTR lpSubKey
	)
#ifdef YY_Thunks_Defined
	;
#else
{
	return SHDeleteKeyW(hKey, lpSubKey);
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegDeleteTreeW, 8);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WIN6)
//Windows Vista, Windows Server 2008

EXTERN_C
LSTATUS
APIENTRY
RegDeleteTreeA(
    _In_ HKEY hKey,
    _In_opt_ LPCSTR lpSubKey
    )
#ifdef YY_Thunks_Defined
	;
#else
{
	return SHDeleteKeyA(hKey, lpSubKey);
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegDeleteTreeA, 8);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WS03SP1)
//Windows Vista, Windows XP Professional x64 Edition, Windows Server 2008, Windows Server 2003 with SP1

EXTERN_C
LSTATUS
APIENTRY
RegGetValueW(
    HKEY    hkey,
    LPCWSTR lpSubKey,
    LPCWSTR lpValue,
    DWORD   dwFlags,
    LPDWORD pdwType,
    PVOID   pvData,
    LPDWORD pcbData
    )
#ifdef YY_Thunks_Defined
	;
#else
{
#if (YY_Thunks_Support_Version >= NTDDI_WINXPSP2)
	return SHRegGetValueW(hkey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
#else
	if (auto const pRegGetValueW = try_get_RegGetValueW())
	{
		return pRegGetValueW(hkey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
	}

	if (pvData && pcbData == nullptr
		|| (dwFlags & RRF_RT_ANY) == 0)
	{
		return ERROR_INVALID_PARAMETER;
	}

	LSTATUS lStatus;

	if (lpSubKey&&*lpSubKey)
	{
		lStatus = RegOpenKeyExW(hkey, lpSubKey, 0, KEY_QUERY_VALUE, &hkey);
		if (lStatus != ERROR_SUCCESS)
			return lStatus;
	}

	DWORD dwType;
	DWORD cbData = pvData && pcbData ? *pcbData : 0;
	const auto cbDataBackup = cbData;


	lStatus = RegQueryValueExW(hkey, lpValue, nullptr, &dwType, (LPBYTE)pvData, &cbData);

	DWORD cbDataFix;
	if (lStatus == ERROR_SUCCESS
		|| lStatus == ERROR_MORE_DATA)
	{
		if (dwType == REG_MULTI_SZ)
		{
			//����2�� null ��β
			cbDataFix = cbData + sizeof(*lpValue) * 2;
		}
		else if (dwType == REG_SZ)
		{
			//һ��null ��β
			cbDataFix = cbData + sizeof(*lpValue);
		}
		else if (dwType == REG_EXPAND_SZ)
		{
			if (dwFlags & RRF_NOEXPAND)
			{
				//һ��null ��β
				cbDataFix = cbData + sizeof(*lpValue);
			}
			else
			{
				//��Ҫչ��
				cbDataFix = pvData && pcbData ? *pcbData : 0;
				lStatus = SHQueryValueExW(hkey, lpValue, nullptr, &dwType, pvData, &cbDataFix);

				if (lStatus == ERROR_SUCCESS
					|| lStatus == ERROR_MORE_DATA)
				{
					cbData = cbDataFix;
				}
			}
		}
		else
		{
			cbDataFix = cbData;
		}
	}

	if (lpSubKey&&*lpSubKey)
	{
		RegCloseKey(hkey);
	}


	if (lStatus == ERROR_SUCCESS
		|| lStatus == ERROR_MORE_DATA)
	{
		if (pdwType)
			*pdwType = dwType;

		//��������Ƿ�֧��
		switch (dwType)
		{
		case REG_NONE:
		case REG_SZ:
		case REG_EXPAND_SZ:
		case REG_BINARY:
		case REG_DWORD:
			if ((dwFlags & (1 << dwType)) == 0)
			{
				lStatus = ERROR_UNSUPPORTED_TYPE;
				break;
			}
			else if (pvData && lStatus == ERROR_SUCCESS)
			{
				//�������ɹ�ʱ����֤�ַ������� NULL ��β
				if (REG_SZ == dwType || REG_EXPAND_SZ == dwType)
				{
					//��֤1�� NULL ��β


					//sizeof(wchar_t) �߽����
					if (cbData % sizeof(*lpValue))
					{
						if (cbData >= cbDataBackup)
						{
							lStatus = ERROR_MORE_DATA;
							break;
						}

						((byte*)pvData)[cbData] = 0;

						++cbData;
					}


					auto cStringMin = cbData / sizeof(*lpValue);


					auto pString = (wchar_t*)pvData;

					if (cStringMin == 0 || pString[cStringMin - 1])
					{
						if (cbData + sizeof(*lpValue) > cbDataBackup)
						{
							lStatus = ERROR_MORE_DATA;
							break;
						}

						pString[cStringMin++] = L'\0';
					}

					cbDataFix = cStringMin * sizeof(*lpValue);
				}
			}
			break;
		case REG_MULTI_SZ:
			if ((dwFlags & RRF_RT_REG_MULTI_SZ) == 0)
			{
				lStatus = ERROR_UNSUPPORTED_TYPE;
			}
			else if (pvData && lStatus == ERROR_SUCCESS)
			{
				//��֤���һ���ַ��� NULL ��β ���� ���� NULL ������

				//sizeof(wchar_t) �߽����
				if (cbData % sizeof(*lpValue))
				{
					if (cbData >= cbDataBackup)
					{
						lStatus = ERROR_MORE_DATA;
						break;
					}

					((byte*)pvData)[cbData] = 0;

					++cbData;
				}

				auto cStringMin = cbData / sizeof(*lpValue);

				auto pString = (wchar_t*)pvData;

				if (cStringMin == 0)
				{
					if (cbData + sizeof(*lpValue) > cbDataBackup)
					{
						lStatus = ERROR_MORE_DATA;
						break;
					}

					pString[cStringMin++] = L'\0';
				}
				else if (pString[cStringMin - 1])
				{
					if (cbData + sizeof(*lpValue) * 2 > cbDataBackup)
					{
						lStatus = ERROR_MORE_DATA;
						break;
					}

					pString[cStringMin++] = L'\0';

					pString[cStringMin++] = L'\0';
				}
				else if (cStringMin >= 2 && pString[cStringMin - 2])
				{
					if (cbData + sizeof(*lpValue) > cbDataBackup)
					{
						lStatus = ERROR_MORE_DATA;
						break;
					}

					pString[cStringMin++] = L'\0';
				}

				cbDataFix = cStringMin * sizeof(*lpValue);
			}
			break;
		case REG_QWORD:
			if ((dwFlags & RRF_RT_REG_QWORD) == 0)
			{
				lStatus = ERROR_UNSUPPORTED_TYPE;
			}
			break;
		default:
			if((dwFlags & RRF_RT_ANY) != RRF_RT_ANY)
				lStatus = ERROR_UNSUPPORTED_TYPE;
			break;
		}

		if (pcbData)
			*pcbData = cbDataFix;

	}


	if ((RRF_ZEROONFAILURE & dwFlags) != 0 && lStatus)
	{
		//ȫ0���
		if (pvData && cbDataBackup)
		{
			memset(pvData, 0, cbDataBackup);
		}
	}

	return lStatus;
#endif
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegGetValueW, 28);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WS03SP1)
//Windows Vista, Windows XP Professional x64 Edition, Windows Server 2008, Windows Server 2003 with SP1

EXTERN_C
LSTATUS
APIENTRY
RegGetValueA(
    HKEY    hkey,
    LPCSTR  lpSubKey,
    LPCSTR  lpValue,
    DWORD   dwFlags,
    LPDWORD pdwType,
    PVOID   pvData,
    LPDWORD pcbData
    )
#ifdef YY_Thunks_Defined
	;
#else
{
#if (YY_Thunks_Support_Version >= NTDDI_WINXPSP2)
	return SHRegGetValueA(hkey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
#else
	if (auto const pRegGetValueA = try_get_RegGetValueA())
	{
		return pRegGetValueA(hkey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
	}

	if (pvData && pcbData == nullptr
		|| (dwFlags & RRF_RT_ANY) == 0)
	{
		return ERROR_INVALID_PARAMETER;
	}

	LSTATUS lStatus;

	if (lpSubKey&&*lpSubKey)
	{
		lStatus = RegOpenKeyExA(hkey, lpSubKey, 0, KEY_QUERY_VALUE, &hkey);
		if (lStatus != ERROR_SUCCESS)
			return lStatus;
	}

	DWORD dwType;
	DWORD cbData = pvData && pcbData ? *pcbData : 0;
	const auto cbDataBackup = cbData;


	lStatus = RegQueryValueExA(hkey, lpValue, nullptr, &dwType, (LPBYTE)pvData, &cbData);

	DWORD cbDataFix;
	if (lStatus == ERROR_SUCCESS
		|| lStatus == ERROR_MORE_DATA)
	{
		if (dwType == REG_MULTI_SZ)
		{
			//����2�� null ��β
			cbDataFix = cbData + sizeof(*lpValue) * 2;
		}
		else if (dwType == REG_SZ)
		{
			//һ��null ��β
			cbDataFix = cbData + sizeof(*lpValue);
		}
		else if (dwType == REG_EXPAND_SZ)
		{
			if (dwFlags & RRF_NOEXPAND)
			{
				//һ��null ��β
				cbDataFix = cbData + sizeof(*lpValue);
			}
			else
			{
				//��Ҫչ��
				cbDataFix = pvData && pcbData ? *pcbData : 0;
				lStatus = SHQueryValueExA(hkey, lpValue, nullptr, &dwType, pvData, &cbDataFix);

				if (lStatus == ERROR_SUCCESS
					|| lStatus == ERROR_MORE_DATA)
				{
					cbData = cbDataFix;
				}
			}
		}
		else
		{
			cbDataFix = cbData;
		}
	}

	if (lpSubKey&&*lpSubKey)
	{
		RegCloseKey(hkey);
	}


	if (lStatus == ERROR_SUCCESS
		|| lStatus == ERROR_MORE_DATA)
	{
		if (pdwType)
			*pdwType = dwType;

		//��������Ƿ�֧��
		switch (dwType)
		{
		case REG_NONE:
		case REG_SZ:
		case REG_EXPAND_SZ:
		case REG_BINARY:
		case REG_DWORD:
			if ((dwFlags & (1<< dwType)) == 0)
			{
				lStatus = ERROR_UNSUPPORTED_TYPE;
			}
			else if (pvData && lStatus == ERROR_SUCCESS)
			{
				//�������ɹ�ʱ����֤�ַ������� NULL ��β
				if (REG_SZ == dwType || REG_EXPAND_SZ == dwType)
				{
					//��֤1�� NULL ��β
					auto cStringMin = cbData;


					auto pString = (char*)pvData;

					if (cStringMin == 0 || pString[cStringMin - 1])
					{
						if (cbData + sizeof(*lpValue) > cbDataBackup)
						{
							lStatus = ERROR_MORE_DATA;
							break;
						}

						pString[cStringMin++] = '\0';
					}

					cbDataFix = cStringMin * sizeof(*lpValue);
				}				
			}
			break;
		case REG_MULTI_SZ:
			if ((dwFlags & RRF_RT_REG_MULTI_SZ) == 0)
			{
				lStatus = ERROR_UNSUPPORTED_TYPE;
			}
			else
			{
				//��֤���һ���ַ��� NULL ��β ���� ���� NULL ������

				auto cStringMin = cbData;

				auto pString = (char*)pvData;

				if (cStringMin == 0)
				{
					if (cbData + sizeof(*lpValue) > cbDataBackup)
					{
						lStatus = ERROR_MORE_DATA;
						break;
					}

					pString[cStringMin++] = '\0';
				}
				else if (pString[cStringMin - 1])
				{
					if (cbData + sizeof(*lpValue) * 2 > cbDataBackup)
					{
						lStatus = ERROR_MORE_DATA;
						break;
					}

					pString[cStringMin++] = '\0';

					pString[cStringMin++] = '\0';
				}
				else if (cStringMin >= 2 && pString[cStringMin - 2])
				{
					if (cbData + sizeof(*lpValue) > cbDataBackup)
					{
						lStatus = ERROR_MORE_DATA;
						break;
					}

					pString[cStringMin++] = '\0';
				}

				cbDataFix = cStringMin * sizeof(*lpValue);
			}
			break;
		case REG_QWORD:
			if ((dwFlags & RRF_RT_REG_QWORD) == 0)
			{
				lStatus = ERROR_UNSUPPORTED_TYPE;
			}
			break;
		default:
			if((dwFlags & RRF_RT_ANY) != RRF_RT_ANY)
				lStatus = ERROR_UNSUPPORTED_TYPE;
			break;
		}

		if (pcbData)
			*pcbData = cbDataFix;

	}


	if ((RRF_ZEROONFAILURE & dwFlags) != 0 && lStatus)
	{
		//ȫ0���
		if (pvData && cbDataBackup)
		{
			memset(pvData, 0, cbDataBackup);
		}
	}

	return lStatus;
#endif
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegGetValueA, 28);
#endif

#if (YY_Thunks_Support_Version < NTDDI_WIN6)
//Windows Vista [desktop apps only]
//Windows Server 2008 [desktop apps only]

EXTERN_C
LSTATUS
APIENTRY
RegCopyTreeW(
    _In_ HKEY hKeySrc,
    _In_opt_ LPCWSTR lpSubKey,
    _In_ HKEY hKeyDest
    )
#ifdef YY_Thunks_Defined
	;
#else
{
	if (auto const pRegCopyTreeW = try_get_RegCopyTreeW())
	{
		return pRegCopyTreeW(hKeySrc, lpSubKey, hKeyDest);
	}

	return SHCopyKeyW(hKeySrc, lpSubKey, hKeyDest, 0);
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegCopyTreeW, 12);

#endif


#if (YY_Thunks_Support_Version < NTDDI_WIN6)
//Windows Vista [desktop apps only]
//Windows Server 2008 [desktop apps only]

EXTERN_C
LSTATUS
APIENTRY
RegCopyTreeA(
    _In_        HKEY     hKeySrc,
    _In_opt_    LPCSTR  lpSubKey,
    _In_        HKEY     hKeyDest
    )
#ifdef YY_Thunks_Defined
	;
#else
{
	if (auto const pRegCopyTreeA = try_get_RegCopyTreeA())
	{
		return pRegCopyTreeA(hKeySrc, lpSubKey, hKeyDest);
	}

	return SHCopyKeyA(hKeySrc, lpSubKey, hKeyDest, 0);
}
#endif

__YY_Thunks_Expand_Function(advapi32, RegCopyTreeA, 12);

#endif

	}//namespace Thunks

} //namespace YY