// file: dcmod.exe, functions: 138, hexrays: True

//==== sub_7E98 @ 0x7e98
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_7E98(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  MEMORY[0x497400268418] = v5;
  v9 = &v10;
  result = MEMORY[0x7FF628432C00](a1, a2, a5, v8, v6, 0);
  if ( result )
    MEMORY[0x497400268418] = MEMORY[0x497400268408] - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A587A71LL;
  return result;
}


//==== sub_7EFA @ 0x7efa
__int64 __fastcall sub_7EFA(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  MEMORY[0x497400268418] = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    MEMORY[0x497400268418] = MEMORY[0x497400268408] - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_9B1F @ 0x9b1f
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_9B1F(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_99B3 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_9A29 + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_99B3 + 2) = **(_QWORD **)((char *)&loc_99C0 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A589631LL;
  return result;
}


//==== sub_9B81 @ 0x9b81
__int64 __fastcall sub_9B81(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_99B3 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_99B3 + 2) = **(_QWORD **)((char *)&loc_99C0 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_CEE6 @ 0xcee6
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_CEE6(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_CD26 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_CD9C + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_CD26 + 2) = **(_QWORD **)((char *)&loc_CD33 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A58AF71LL;
  return result;
}


//==== sub_CF48 @ 0xcf48
__int64 __fastcall sub_CF48(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_CD26 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_CD26 + 2) = **(_QWORD **)((char *)&loc_CD33 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== nullsub_1 @ 0x17a88
void __fastcall nullsub_1(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40)
{
  ;
}


//==== sub_1A253 @ 0x1a253
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1A253(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1A126 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_1A19C + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_1A126 + 2) = **(_QWORD **)((char *)&loc_1A133 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A599E71LL;
  return result;
}


//==== sub_1A2B5 @ 0x1a2b5
__int64 __fastcall sub_1A2B5(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1A126 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_1A126 + 2) = **(_QWORD **)((char *)&loc_1A133 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_1A587 @ 0x1a587
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1A587(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1A431 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_1A4A7 + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_1A431 + 2) = **(_QWORD **)((char *)&loc_1A43E + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A59A131LL;
  return result;
}


//==== sub_1A5E9 @ 0x1a5e9
__int64 __fastcall sub_1A5E9(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1A431 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_1A431 + 2) = **(_QWORD **)((char *)&loc_1A43E + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_1A8F9 @ 0x1a8f9
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1A8F9(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1A786 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_1A7FC + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_1A786 + 2) = **(_QWORD **)((char *)&loc_1A793 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A59A471LL;
  return result;
}


//==== sub_1A95B @ 0x1a95b
__int64 __fastcall sub_1A95B(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1A786 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_1A786 + 2) = **(_QWORD **)((char *)&loc_1A793 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_1ABDA @ 0x1abda
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1ABDA(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1AAA6 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_1AB1C + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_1AAA6 + 2) = **(_QWORD **)((char *)&loc_1AAB3 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A59A7F1LL;
  return result;
}


//==== sub_1AC3C @ 0x1ac3c
__int64 __fastcall sub_1AC3C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1AAA6 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_1AAA6 + 2) = **(_QWORD **)((char *)&loc_1AAB3 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_28CF0 @ 0x28cf0
__int64 __fastcall sub_28CF0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48,
        __int64 a49)
{
  return MEMORY[0xC10152C2E100000A];
}


//==== sub_28E70 @ 0x28e70
__int64 sub_28E70()
{
  return MEMORY[0x410152C36500000A];
}


//==== sub_42119 @ 0x42119
void __fastcall sub_42119(__int64 _RDI)
{
  *(_DWORD *)(_RDI - 1) = 1301;
  __asm { vmovsd  qword ptr [rdi+3], xmm15 }
  JUMPOUT(0x41D69);
}


//==== sub_4214C @ 0x4214c
void __fastcall sub_4214C(__int64 a1, __int64 a2, __int64 a3, __int64 _RCX)
{
  *(_DWORD *)(_RCX - 1) = 1301;
  __asm { vmovsd  qword ptr [rcx+3], xmm15 }
  JUMPOUT(0x41E0F);
}


//==== sub_4217F @ 0x4217f
void __fastcall sub_4217F(__int64 a1, __int64 a2, __int64 _RDX)
{
  *(_DWORD *)(_RDX - 1) = 1301;
  __asm { vmovsd  qword ptr [rdx+3], xmm15 }
  JUMPOUT(0x41EC1);
}


//==== sub_421B2 @ 0x421b2
void __fastcall sub_421B2()
{
  *(_DWORD *)(_RBX - 1) = 1301;
  __asm { vmovsd  qword ptr [rbx+3], xmm15 }
  JUMPOUT(0x41F50);
}


//==== sub_421E5 @ 0x421e5
void __fastcall sub_421E5(__int64 a1, __int64 a2, __int64 _RDX)
{
  *(_DWORD *)(_RDX - 1) = 1301;
  __asm { vmovsd  qword ptr [rdx+3], xmm15 }
  JUMPOUT(0x41F9C);
}


//==== sub_42218 @ 0x42218
void __fastcall sub_42218()
{
  *(_DWORD *)(_RBX - 1) = 1301;
  __asm { vmovsd  qword ptr [rbx+3], xmm15 }
  JUMPOUT(0x4201E);
}


//==== sub_422E2 @ 0x422e2
// bad sp value at call has been detected, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_422E2(
        __int64 _RDI,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // r8
  __int64 v12; // r9
  __int64 v13; // r11
  __int64 n94; // rsi
  __int64 v15; // rbx
  __int64 v16; // rcx
  __int64 v17; // rax
  __int64 v18; // rdx
  __int64 n17851069; // r9
  int n113; // r15d
  __int64 v21; // r12
  bool v22; // of
  __int64 v23; // rdx
  int n2; // ebx
  __int64 n2_2; // rbx
  __int64 n2_1; // rcx
  __int64 v27; // rcx
  int v28; // ebx
  int v29; // ebx
  __int64 v30; // rax
  __int64 v31; // rdx
  __int64 v32; // r8
  __int64 v33; // r9
  int v34; // ecx
  __int64 v35; // rcx
  __int64 v36; // rax
  __int64 v37; // rdx
  __int64 v38; // r8
  __int64 v39; // r9
  __int64 v40; // rcx
  int v41; // eax
  __int64 v42; // rdx
  __int64 v43; // rdx
  __int64 v44; // rax
  __int64 v45; // rcx
  __int64 v46; // rcx
  __int64 v47; // rax
  __int64 v48; // rax
  __int64 v49; // r8
  __int64 v50; // r9
  __int64 v51; // rdx
  __int64 v52; // rcx
  __int64 v53; // rdx
  int v54; // ecx
  __int64 v55; // rcx
  int v56; // ebx
  int v57; // ebx
  __int64 v58; // rcx
  __int64 v59; // rcx
  bool v60; // cc
  __int64 v62; // rdi
  __int64 v64; // rcx
  __int64 v66; // rdx
  unsigned __int64 v68; // r10
  __int64 v70; // rdx
  unsigned __int64 v72; // r10
  __int64 v73; // rdi
  __int64 v74; // rbx
  _QWORD *v75; // rbp
  __int64 v76; // r13
  __int64 v77; // r14
  __int64 n94_1; // r15
  __int64 n94_2; // [rsp-88h] [rbp-88h]
  __int64 n17851069_1; // [rsp-70h] [rbp-70h]
  __int64 v82; // [rsp-68h] [rbp-68h]
  __int64 v83; // [rsp-60h] [rbp-60h]
  __int64 n94_3; // [rsp-58h] [rbp-58h]
  __int64 v85; // [rsp-50h] [rbp-50h]
  __int64 v86; // [rsp-48h] [rbp-48h]
  __int64 v87; // [rsp-40h] [rbp-40h]
  __int64 v88; // [rsp-38h] [rbp-38h]

  while ( 2 )
  {
    *(_DWORD *)(_RDI - 1) = 1301;
    __asm { vmovsd  qword ptr [rdi+3], xmm15 }
    do
    {
      v16 = a3;
      v17 = v74;
      n94 = n94_1;
      v18 = *(v75 - 6);
      v15 = *(v75 - 5);
      *(v75 - 4) = v17;
      *(v75 - 5) = v16;
      *(v75 - 6) = v18;
      *(v75 - 7) = v15;
      *(v75 - 9) = n94_1;
      *(v75 - 8) = _RDI;
      v11 = v75[3];
      if ( (v11 & 1) == 0 || *(_DWORD *)(v11 - 1) > 0x425u )
      {
        (*(void (__fastcall **)(__int64, __int64))(v76 - 40))(_RDI, n94_1);
LABEL_107:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v76 - 40))(
          _RDI,
          n94_1,
          v18,
          v16,
          v11,
          v12);
LABEL_108:
        (*(void (__fastcall **)(__int64, __int64))(v76 - 40))(_RDI, n94_1);
LABEL_109:
        (*(void (__fastcall **)(__int64, __int64))(v76 - 40))(_RDI, n94_1);
LABEL_110:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v18, v16, v11);
LABEL_111:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v18, v16, v11);
LABEL_112:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v18, v16, v11);
LABEL_113:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v18, v16, v11);
LABEL_114:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v16, v11);
LABEL_115:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v16, v11);
LABEL_116:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v16, v11);
LABEL_117:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v16, v11);
LABEL_118:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v27, v11);
LABEL_119:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v27, v11);
LABEL_120:
        (*(void (**)(void))(v76 - 40))();
LABEL_121:
        (*(void (**)(void))(v76 - 40))();
LABEL_122:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v37, v40);
LABEL_123:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v43, v40);
LABEL_124:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v16, v11);
LABEL_125:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v46, v11);
LABEL_126:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v51, v16, v11);
LABEL_127:
        (*(void (**)(void))(v76 - 40))();
LABEL_128:
        (*(void (**)(void))(v76 - 40))();
LABEL_129:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v18, v16, v11);
LABEL_130:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v76 - 40))(
          _RDI,
          n94,
          v18,
          v16,
          v11,
          n17851069,
          v83,
          n94_3,
          v85,
          v86,
          v87,
          v88);
LABEL_131:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(v76 - 40))(
          _RDI,
          n94,
          a3,
          v59,
          v11,
          n17851069);
LABEL_132:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, n2_1, v11);
LABEL_133:
        (*(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v76 - 40))(_RDI, n94, v23, v16, v11);
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        (*(void (**)(void))(v76 - 32))();
        JUMPOUT(0x42536);
      }
      v12 = *(unsigned int *)(v11 + 7);
      v13 = _RDI;
      if ( (_RDI & 1) != 0 )
        goto LABEL_107;
      _RDI = (unsigned int)((int)_RDI >> 1);
      *(v75 - 12) = _RDI;
      if ( (int)_RDI > (int)v12 )
      {
LABEL_89:
        v60 = MEMORY[0x310011063B8] < 458;
        MEMORY[0x310011063B8] -= 458;
        if ( v60 )
          MEMORY[0xFFFFFFFFA00ABBC0](_RDI, 0x3100106770DLL);
        return;
      }
      if ( (int)_RDI >= (int)v12 )
      {
        n17851069 = v75[6];
        if ( (_DWORD)n17851069 != 17851069 )
          goto LABEL_108;
        if ( (n94_1 & 1) != 0 )
          goto LABEL_109;
        if ( (int)n94_1 >> 1 == 47 )
        {
          n113 = v77 + 113;
        }
        else if ( (int)n94_1 >> 1 == 92 )
        {
          n113 = v77 + 113;
        }
        else
        {
          n113 = v77 + 85;
        }
        if ( n113 == 113 )
          goto LABEL_89;
        n94 = 94;
      }
      else
      {
        n94 = MEMORY[0xFFFFFFFF9FFE9840](
                0x3100106D6B5LL,
                0x310011061A5LL,
                v18,
                v16,
                v11,
                (unsigned int)_RDI,
                v77 + 17,
                v11,
                v13);
        v13 = *(v75 - 8);
        v15 = *(v75 - 7);
        v16 = *(v75 - 5);
        v17 = *(v75 - 4);
        v18 = *(v75 - 6);
        _RDI = *(v75 - 12);
        n17851069 = v75[6];
        v11 = v75[3];
      }
      *(v75 - 11) = n94;
      if ( (_DWORD)n17851069 != 17851069 )
        goto LABEL_110;
      n94_1 = n94;
      if ( (n94 & 1) != 0 )
        goto LABEL_111;
      n94 = (unsigned int)((int)n94 >> 1);
      *(v75 - 14) = n94;
      if ( (_DWORD)n94 == 47 )
      {
        *(v75 - 10) = v77 + 113;
      }
      else
      {
        if ( (_DWORD)n94 == 92 )
          v21 = v77 + 113;
        else
          v21 = v77 + 85;
        *(v75 - 10) = v21;
      }
      if ( (unsigned int)*(v75 - 10) == 113 )
      {
        v22 = __OFSUB__((_DWORD)_RDI, 1);
        _RDI = (unsigned int)(_RDI - 1);
        if ( v22 )
          goto LABEL_112;
        if ( (v18 & 1) != 0 )
          goto LABEL_113;
        v23 = (unsigned int)((int)v18 >> 1);
        *(v75 - 15) = v23;
        if ( (_DWORD)_RDI == (_DWORD)v23 )
        {
          _RDI = 1;
LABEL_33:
          v74 = v17;
          a3 = v16;
LABEL_75:
          n94 = 0xFFFFFFFFLL;
          *(v75 - 6) = v13;
          *(v75 - 5) = 0;
          goto LABEL_84;
        }
        if ( (v15 & 1) != 0 )
          goto LABEL_114;
        n2 = (int)v15 >> 1;
        _RDI = 1;
        if ( n2 == 1 )
          goto LABEL_33;
        if ( n2 != 2 )
        {
          if ( (v17 & 1) == 0 || *(_DWORD *)(v17 - 1) > 0x425u )
            goto LABEL_124;
          _RDI = 0;
          if ( *(int *)(v17 + 7) <= 0 )
          {
            v22 = __OFADD__(1, (_DWORD)v23);
            v51 = (unsigned int)(v23 + 1);
            if ( v22 )
              goto LABEL_126;
            if ( __OFADD__((_DWORD)v51, (_DWORD)v51) )
            {
              __asm { vcvtsi2sd xmm15, xmm15, edx }
              v68 = *(_QWORD *)(v76 + 80) + 12LL;
              if ( v68 >= *(_QWORD *)(v76 + 88) )
              {
                ((void (__fastcall *)(_QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))sub_423AA)(
                  0,
                  n94,
                  v51,
                  v16,
                  v11,
                  n17851069,
                  a7,
                  a8,
                  a9,
                  a10);
              }
              else
              {
                *(_QWORD *)(v76 + 80) = v68;
                sub_421B2();
              }
              return;
            }
            _RDI = 0x3100106BEC9LL;
            n94 = 0x310011061A5LL;
            v48 = MEMORY[0xFFFFFFFF9FFE9840](
                    0x3100106BEC9LL,
                    0x310011061A5LL,
                    v51,
                    v16,
                    v11,
                    n17851069,
                    v77 + 17,
                    v11,
                    (unsigned int)(2 * v51),
                    v13);
          }
          else
          {
            n94 = 0x310011061A5LL;
            v44 = v75[5];
            if ( (v44 & 1) == 0 || *(_DWORD *)(v44 - 1) > 0x425u )
              v44 = MEMORY[0xFFFFFFFFA00FEB40](0, 0x310011061A5LL, v23, v16, v11);
            *(v75 - 10) = v44;
            v45 = *(v75 - 15);
            v22 = __OFADD__(1, (_DWORD)v45);
            v46 = (unsigned int)(v45 + 1);
            if ( v22 )
              goto LABEL_125;
            if ( __OFADD__((_DWORD)v46, (_DWORD)v46) )
            {
              __asm { vcvtsi2sd xmm15, xmm15, ecx }
              v66 = *(_QWORD *)(v76 + 80);
              if ( (unsigned __int64)(v66 + 12) >= *(_QWORD *)(v76 + 88) )
              {
                ((void (__fastcall *)(_QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))sub_42383)(
                  0,
                  0x310011061A5LL,
                  v66,
                  v46,
                  v11,
                  n17851069,
                  a7,
                  a8,
                  a9,
                  a10);
              }
              else
              {
                *(_QWORD *)(v76 + 80) = v66 + 12;
                sub_4217F(0, 0x310011061A5LL, v66 + 1);
              }
              return;
            }
            _RDI = 0x3100106BEC9LL;
            v47 = MEMORY[0xFFFFFFFF9FFE9840](
                    0x3100106BEC9LL,
                    0x310011061A5LL,
                    (unsigned int)(2 * v46),
                    v46,
                    v11,
                    n17851069,
                    v77 + 17,
                    v75[3],
                    (unsigned int)(2 * v46),
                    *(v75 - 8));
            if ( (v47 & 1) == 0 || *(_DWORD *)(v47 - 1) > 0x425u )
              MEMORY[0xFFFFFFFFA00FEB40](0x3100106BEC9LL, 0x310011061A5LL);
            MEMORY[0xFFFFFFFFA00AC040](0x3100106BEC9LL, 0x3100106770DLL);
            n94 = 0x3100106770DLL;
            v48 = MEMORY[0xFFFFFFFFA00AC040](0x3100106BEC9LL, 0x3100106770DLL);
          }
          v52 = *(v75 - 12);
          v53 = *(v75 - 15);
          v22 = __OFSUB__((_DWORD)v52, (_DWORD)v53);
          v54 = v52 - v53;
          if ( v22 )
            goto LABEL_127;
          v22 = __OFSUB__(v54, 1);
          v55 = (unsigned int)(v54 - 1);
          if ( v22 )
            goto LABEL_128;
          a3 = (unsigned int)(2 * v55);
          if ( __OFADD__((_DWORD)v55, (_DWORD)v55) )
          {
            __asm { vcvtsi2sd xmm15, xmm15, ecx }
            v70 = *(_QWORD *)(v76 + 80);
            if ( (unsigned __int64)(v70 + 12) >= *(_QWORD *)(v76 + 88) )
            {
              ((void (__stdcall *)(__int64, __int64, __int64, __int64, __int64))sub_423EB)(v55, v70, v49, v50, a11);
            }
            else
            {
              *(_QWORD *)(v76 + 80) = v70 + 12;
              sub_421E5(0x3100106BEC9LL, n94, v70 + 1);
            }
            return;
          }
          v74 = v48;
          _RDI = 1;
          n94_1 = *(v75 - 11);
          v17 = *(v75 - 4);
          n17851069 = v75[6];
          v13 = *(v75 - 8);
          v11 = v75[3];
          goto LABEL_75;
        }
        if ( (v17 & 1) == 0 || *(_DWORD *)(v17 - 1) > 0x425u )
          goto LABEL_115;
        n2_2 = *(unsigned int *)(v17 + 7);
        *(v75 - 13) = n2_2;
        if ( (int)n2_2 >= 2 )
        {
          if ( (v16 & 1) != 0 )
            goto LABEL_116;
          n2_1 = (unsigned int)((int)v16 >> 1);
          if ( (_DWORD)n2_1 == 2 )
            goto LABEL_132;
          v16 = *(v75 - 5);
        }
        if ( (int)n2_2 <= 2 )
          goto LABEL_133;
        if ( (v16 & 1) != 0 )
          goto LABEL_117;
        v27 = (unsigned int)((int)v16 >> 1);
        v22 = __OFSUB__((_DWORD)n2_2, (_DWORD)v27);
        v28 = n2_2 - v27;
        if ( v22 )
          goto LABEL_118;
        v22 = __OFSUB__(v28, 1);
        v29 = v28 - 1;
        if ( v22 )
          goto LABEL_119;
        if ( v29 == -1 )
        {
          v74 = v77 + 73;
          *(v75 - 10) = 0;
        }
        else
        {
          if ( __OFADD__(v29, v29) )
          {
            __asm { vcvtsi2sd xmm15, xmm15, ebx }
            v62 = *(_QWORD *)(v76 + 80);
            if ( (unsigned __int64)(v62 + 12) >= *(_QWORD *)(v76 + 88) )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))sub_4231D)(
                v62,
                n94,
                v23,
                0xFFFFFFFFLL,
                v11,
                n17851069,
                a7,
                a8,
                a9,
                a10);
            }
            else
            {
              *(_QWORD *)(v76 + 80) = v62 + 12;
              sub_42119(v62 + 1);
            }
            return;
          }
          _RDI = 0x3100106BEC9LL;
          n94 = 0x310011061A5LL;
          v30 = MEMORY[0xFFFFFFFF9FFE9840](
                  0x3100106BEC9LL,
                  0x310011061A5LL,
                  v23,
                  0xFFFFFFFFLL,
                  v11,
                  n17851069,
                  v77 + 17,
                  v17,
                  0,
                  (unsigned int)(2 * v29));
          *(v75 - 10) = v30;
          if ( (v30 & 1) == 0 || *(_DWORD *)(v30 - 1) > 0x425u )
            goto LABEL_120;
          v34 = *(_DWORD *)(v30 + 7);
          v22 = __OFSUB__(v34, 1);
          v35 = (unsigned int)(v34 - 1);
          if ( v22 )
            goto LABEL_121;
          *(v75 - 16) = (unsigned int)v35;
          _RDI = 0x31001092239LL;
          n94 = 0x310011061A5LL;
          v36 = MEMORY[0xFFFFFFFF9FFE9840](0x31001092239LL, 0x310011061A5LL, v31, v35, v32, v33, v77 + 17, v30, v75[5]);
          v40 = v36;
          if ( (v36 & 1) != 0 )
            goto LABEL_122;
          v41 = (int)v36 >> 1;
          v42 = *(v75 - 16);
          v22 = __OFSUB__((_DWORD)v42, v41);
          v43 = (unsigned int)(v42 - v41);
          if ( v22 )
            goto LABEL_123;
          if ( __OFADD__((_DWORD)v43, (_DWORD)v43) )
          {
            __asm { vcvtsi2sd xmm15, xmm15, edx }
            v64 = *(_QWORD *)(v76 + 80);
            if ( (unsigned __int64)(v64 + 12) >= *(_QWORD *)(v76 + 88) )
            {
              ((void (__stdcall *)(__int64, __int64, __int64, __int64, __int64))sub_4235E)(v64, v43, v38, v39, a11);
            }
            else
            {
              *(_QWORD *)(v76 + 80) = v64 + 12;
              sub_4214C(0x31001092239LL, 0x310011061A5LL, v43, v64 + 1);
            }
            return;
          }
          v74 = *(v75 - 10);
          *(v75 - 10) = (unsigned int)(2 * v43);
          _RDI = 1;
          v11 = v75[3];
          v17 = *(v75 - 4);
          n17851069 = v75[6];
          v13 = *(v75 - 8);
          n94_1 = *(v75 - 11);
        }
        n94 = 0xFFFFFFFFLL;
        *(v75 - 6) = v13;
        a3 = *(v75 - 10);
        *(v75 - 5) = 0;
      }
      else
      {
        if ( (_DWORD)n94 != 46 )
        {
          n94 = 0xFFFFFFFFLL;
LABEL_83:
          v74 = v17;
          *(v75 - 6) = v18;
          a3 = v16;
          _RDI = 1;
          *(v75 - 5) = 4294967294LL;
          goto LABEL_84;
        }
        if ( (v15 & 1) != 0 )
          goto LABEL_129;
        v56 = (int)v15 >> 1;
        n94 = 0xFFFFFFFFLL;
        if ( v56 == -1 )
          goto LABEL_83;
        v22 = __OFADD__(1, v56);
        v57 = v56 + 1;
        if ( v22 )
          goto LABEL_130;
        if ( __OFADD__(v57, v57) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, ebx }
          v72 = *(_QWORD *)(v76 + 80) + 12LL;
          if ( v72 >= *(_QWORD *)(v76 + 88) )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))sub_42412)(
              _RDI,
              0xFFFFFFFFLL,
              v18,
              v16,
              v11,
              n17851069,
              a7,
              a8,
              a9,
              a10);
          }
          else
          {
            *(_QWORD *)(v76 + 80) = v72;
            sub_42218();
          }
          return;
        }
        *(v75 - 5) = (unsigned int)(2 * v57);
        v74 = v17;
        *(v75 - 6) = v18;
        a3 = v16;
        _RDI = 1;
      }
LABEL_84:
      *(v75 - 7) = v74;
      *(v75 - 10) = a3;
      v58 = *(v75 - 12);
      v22 = __OFADD__(1, (_DWORD)v58);
      v59 = (unsigned int)(v58 + 1);
      if ( v22 )
        goto LABEL_131;
      *(v75 - 14) = (unsigned int)v59;
      v60 = MEMORY[0x310011063B8] < 348;
      MEMORY[0x310011063B8] -= 348;
      if ( v60 )
      {
        MEMORY[0xFFFFFFFFA00ABBC0](
          1,
          0x3100106770DLL,
          a3,
          v59,
          v11,
          n17851069,
          *(v75 - 2),
          n94_1,
          2,
          0x310011063ADLL,
          n17851069,
          v11,
          1,
          0xFFFFFFFFLL,
          v74,
          a3,
          (unsigned int)v59,
          v17);
        n94_1 = n94_2;
        n17851069 = n17851069_1;
        v11 = v82;
        n94 = n94_3;
        v74 = v85;
        a3 = v86;
        v59 = v87;
      }
      _RDI = (unsigned int)(2 * v59);
    }
    while ( !__OFADD__((_DWORD)v59, (_DWORD)v59) );
    __asm { vcvtsi2sd xmm15, xmm15, ecx }
    v73 = *(_QWORD *)(v76 + 80);
    if ( (unsigned __int64)(v73 + 12) < *(_QWORD *)(v76 + 88) )
    {
      *(_QWORD *)(v76 + 80) = v73 + 12;
      _RDI = v73 + 1;
      continue;
    }
    break;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))sub_42455)(
    v73,
    n94,
    a3,
    v59,
    v11,
    n17851069,
    a7,
    a8,
    a9,
    a10,
    a11);
}


//==== sub_4231D @ 0x4231d
void __fastcall sub_4231D(__int64 a1, __int64 a2)
{
  __int64 _RDI; // rax

  __asm { vmovsd  [rsp+50h+var_50], xmm15 }
  _RDI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+50h+var_50] }
  sub_42119(_RDI);
}


//==== sub_4235E @ 0x4235e
void __fastcall sub_4235E(__int64 a1, __int64 a2)
{
  __int64 _RCX; // rax
  __int64 v5; // rdx

  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  _RCX = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+8+var_8] }
  sub_4214C(a1, a2, v5, _RCX);
}


//==== sub_42383 @ 0x42383
void __fastcall sub_42383(__int64 a1, __int64 a2)
{
  __int64 _RDX; // rax

  __asm { vmovsd  [rsp+10h+var_10], xmm15 }
  _RDX = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+10h+var_10] }
  sub_4217F(a1, a2, _RDX);
}


//==== sub_423AA @ 0x423aa
void __fastcall sub_423AA(__int64 a1, __int64 a2)
{
  __asm { vmovsd  [rsp+50h+var_50], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+50h+var_50] }
  sub_421B2();
}


//==== sub_423EB @ 0x423eb
void __fastcall sub_423EB(__int64 a1, __int64 n94)
{
  __int64 _RDX; // rax

  __asm { vmovsd  [rsp+10h+var_10], xmm15 }
  _RDX = MEMORY[0xFFFFFFFF9FFF7E80](a1, n94, 12);
  __asm { vmovsd  xmm15, [rsp+10h+var_10] }
  sub_421E5(a1, n94, _RDX);
}


//==== sub_42412 @ 0x42412
void __fastcall sub_42412(__int64 a1, __int64 a2)
{
  __asm { vmovsd  [rsp+58h+var_58], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+58h+var_58] }
  sub_42218();
}


//==== sub_42455 @ 0x42455
void __fastcall sub_42455(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 _RDI; // rax
  __int64 v14; // rcx

  __asm { vmovsd  [rsp+50h+var_50], xmm15 }
  _RDI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+50h+var_50] }
  sub_422E2(_RDI, a2, a3, v14, a5, a6, a7, a8, a9, a10, a11);
}


//==== nullsub_2 @ 0x70608
__int64 __fastcall nullsub_2(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39)
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)(
           a4,
           a3,
           a5,
           a6,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38);
}


//==== sub_7A342 @ 0x7a342
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_7A342(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  MEMORY[0x497400268418] = v5;
  v9 = &v10;
  result = MEMORY[0x7FF628432C00](a1, a2, a5, v8, v6, 0);
  if ( result )
    MEMORY[0x497400268418] = MEMORY[0x497400268408] - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A5F9EB1LL;
  return result;
}


//==== sub_7A3A4 @ 0x7a3a4
__int64 __fastcall sub_7A3A4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  MEMORY[0x497400268418] = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    MEMORY[0x497400268418] = MEMORY[0x497400268408] - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_BD1AE @ 0xbd1ae
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_BD1AE(
        __m128 _XMM0,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // zf
  char v9; // pf
  __int64 v10; // r13
  bool v15; // of
  __int64 result; // rax
  __int64 v17; // rax

  __asm
  {
    vcvttpd2dq xmm15, xmm0
    vcvtdq2pd xmm15, xmm15
    vucomisd xmm15, xmm0
  }
  if ( v9 )
    goto LABEL_7;
  if ( !v8 )
    goto LABEL_7;
  __asm { vcvttsd2si eax, xmm0 }
  if ( !_EAX )
  {
    __asm { vpextrd r10d, xmm0, 1 }
    if ( _R10D < 0 )
      goto LABEL_7;
  }
  v15 = __OFADD__(_EAX, _EAX);
  result = (unsigned int)(2 * _EAX);
  if ( v15 )
  {
LABEL_7:
    v17 = *(_QWORD *)(v10 + 80);
    if ( (unsigned __int64)(v17 + 12) >= *(_QWORD *)(v10 + 88) )
    {
      return ((__int64 (__stdcall *)(__int64))sub_BD2D2)(a5);
    }
    else
    {
      *(_QWORD *)(v10 + 80) = v17 + 12;
      result = v17 + 1;
      *(_DWORD *)(result - 1) = 1301;
      __asm { vmovsd  qword ptr [rax+3], xmm0 }
    }
  }
  return result;
}


//==== sub_BD299 @ 0xbd299
__int64 __fastcall sub_BD299(
        __int64 a1,
        __m128 _XMM0,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // rbp
  __m128 _XMM0; // xmm0
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // r8
  __int64 v13; // r9
  __int64 v15; // [rsp+0h] [rbp-10h]

  __asm { vmovsd  [rsp+8+var_8], xmm0 }
  v15 = *(_QWORD *)(v8 - 16);
  MEMORY[0xFFFFFFFFA00ABBC0](a1, 0x3100106770DLL);
  __asm { vmovsd  xmm0, [rsp+10h+var_10] }
  return sub_BD1AE(_XMM0, a1, 0x3100106770DLL, v10, v11, v12, v13, a8);
}


//==== sub_BD2D2 @ 0xbd2d2
void __fastcall sub_BD2D2(
        __int64 a1,
        __int64 a2,
        __m128 _XMM0,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __asm { vmovsd  [rsp+8+var_8], xmm0 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm0, [rsp+8+var_8] }
  JUMPOUT(0xBD208);
}


//==== nullsub_3 @ 0x103b08
void __fastcall nullsub_3(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42)
{
  ;
}


//==== nullsub_4 @ 0x118975
void __fastcall nullsub_4(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43)
{
  ;
}


//==== sub_11B33C @ 0x11b33c
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_11B33C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_11B20F + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_11B285 + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_11B20F + 2) = **(_QWORD **)((char *)&loc_11B21C + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A69AEF1LL;
  return result;
}


//==== sub_11B39E @ 0x11b39e
__int64 __fastcall sub_11B39E(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_11B20F + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_11B20F + 2) = **(_QWORD **)((char *)&loc_11B21C + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_11B931 @ 0x11b931
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_11B931(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_11B804 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_11B87A + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_11B804 + 2) = **(_QWORD **)((char *)&loc_11B811 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A69B531LL;
  return result;
}


//==== sub_11B993 @ 0x11b993
__int64 __fastcall sub_11B993(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_11B804 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_11B804 + 2) = **(_QWORD **)((char *)&loc_11B811 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_11BCC6 @ 0x11bcc6
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_11BCC6(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_11BB99 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_11BC0F + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_11BB99 + 2) = **(_QWORD **)((char *)&loc_11BBA6 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A69B831LL;
  return result;
}


//==== sub_11BD28 @ 0x11bd28
__int64 __fastcall sub_11BD28(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_11BB99 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_11BB99 + 2) = **(_QWORD **)((char *)&loc_11BBA6 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== nullsub_5 @ 0x12c275
void nullsub_5()
{
  __asm { iret }
}


//==== nullsub_6 @ 0x1830b5
__int64 __fastcall nullsub_6(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43)
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)(
           a4,
           a3,
           a5,
           a6,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42);
}


//==== nullsub_7 @ 0x185aa9
void nullsub_7()
{
  ;
}


//==== sub_185BBA @ 0x185bba
void __fastcall sub_185BBA(__int64 _RDI)
{
  *(_DWORD *)(_RDI - 1) = 1301;
  __asm { vmovsd  qword ptr [rdi+3], xmm15 }
  JUMPOUT(0x184D19);
}


//==== sub_185BEE @ 0x185bee
void __fastcall sub_185BEE(__int64 a1, __int64 _RSI)
{
  *(_DWORD *)(_RSI - 1) = 1301;
  __asm { vmovsd  qword ptr [rsi+3], xmm15 }
  JUMPOUT(0x184D24);
}


//==== sub_185C4B @ 0x185c4b
void __fastcall sub_185C4B(__int64 a1, __int64 _RSI)
{
  *(_DWORD *)(_RSI - 1) = 1301;
  __asm { vmovsd  qword ptr [rsi+3], xmm15 }
  JUMPOUT(0x184EC0);
}


//==== sub_185CBB @ 0x185cbb
void __fastcall sub_185CBB(__int64 _RDI)
{
  *(_DWORD *)(_RDI - 1) = 1301;
  __asm { vmovsd  qword ptr [rdi+3], xmm15 }
  JUMPOUT(0x185040);
}


//==== sub_185D44 @ 0x185d44
void __fastcall sub_185D44()
{
  *(_DWORD *)(_RBX - 1) = 1301;
  __asm { vmovsd  qword ptr [rbx+3], xmm15 }
  JUMPOUT(0x185273);
}


//==== sub_185D77 @ 0x185d77
// bad sp value at call has been detected, the output may be wrong!
void __fastcall sub_185D77(
        __int64 a1,
        __int64 a2,
        __int64 _RDX,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // rdi
  __int64 v9; // rsi
  __int64 v10; // rax
  __int64 v11; // r8
  __int64 v12; // r9
  __int64 n113; // rcx
  int n1301; // r10d
  __int64 (__fastcall *v15)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 (__fastcall *v16)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v17; // r8
  __int64 v18; // r9
  __int64 v19; // rax
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rax
  __int64 n0x71; // rax
  __int64 v24; // rdx
  __int64 v25; // rcx
  __int64 v26; // r8
  __int64 v27; // r9
  int n1301_1; // r10d
  __int64 n113_1; // rax
  int n1341; // r10d
  __int64 v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // rbx
  int v34; // r8d
  __int64 v35; // r8
  __int64 v36; // rdi
  __int64 v37; // rsi
  __int64 v38; // r8
  __int64 v39; // r9
  __int64 (__fastcall *v40)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v41; // rax
  __int64 v42; // rcx
  __int64 v43; // r8
  __int64 (__fastcall *v44)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v45; // r9
  __int64 v46; // rax
  __int64 n23425149; // rax
  __int64 v48; // r8
  __int64 v49; // rcx
  int v50; // edx
  __int64 v51; // rdx
  __int64 (__fastcall *v52)(__int64, __int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64, __int64, __int64); // rcx
  __int64 v53; // rax
  __int64 n23425149_1; // rax
  __int64 v55; // r8
  __int64 v56; // r9
  __int64 v57; // rdi
  __int64 v58; // rax
  int v59; // eax
  bool v60; // of
  unsigned int v61; // eax
  __int64 v62; // rcx
  __int64 v63; // rdx
  __int64 v64; // rbx
  __int64 v65; // r9
  __int64 (__fastcall *v66)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64, _QWORD); // rcx
  __int64 v67; // rcx
  __int64 v68; // rdi
  __int64 v69; // r8
  __int64 (__fastcall *v70)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v71; // r9
  __int64 v72; // rax
  __int64 v73; // rcx
  __int64 n18536041; // rax
  __int64 v75; // rcx
  __int64 v76; // rdi
  __int64 v77; // r8
  __int64 (__fastcall *v78)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v79; // r9
  __int64 v80; // rax
  __int64 v81; // rcx
  int v82; // edx
  __int64 v83; // rdx
  int v84; // esi
  int v85; // esi
  __int64 (__fastcall *v86)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v87; // rcx
  __int64 v88; // rbx
  __int64 v89; // rdi
  __int64 v90; // r8
  __int64 v91; // r9
  __int64 (__fastcall *v92)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v93; // rax
  __int64 v94; // rdx
  __int64 v95; // r8
  __int64 v96; // r9
  __int64 v97; // rcx
  __int64 n28205697; // rax
  __int64 v99; // r8
  __int64 v100; // r9
  void (__fastcall *v101)(__int64, __int64, __int64, _QWORD, __int64, __int64, _QWORD, __int64, _QWORD); // rcx
  int v102; // ebx
  __int64 v103; // rbx
  bool v104; // cc
  __int64 (__fastcall *v105)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v106; // rdi
  __int64 (__fastcall *v107)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v108; // r8
  __int64 v109; // r9
  __int64 v110; // rax
  __int64 v111; // rcx
  __int64 v112; // rcx
  __int64 v113; // rdi
  __int64 v114; // r8
  __int64 (__fastcall *v115)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v116; // r9
  __int64 v117; // rax
  __int64 v118; // rcx
  __int64 v119; // rdi
  __int64 v120; // r8
  __int64 (__fastcall *v121)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v122; // r9
  __int64 v123; // rax
  __int64 v124; // rdi
  __int64 (__fastcall *v125)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v126; // r8
  __int64 v127; // r9
  __int64 v128; // rax
  __int64 v129; // rcx
  __int64 (__fastcall *v130)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v131; // r8
  __int64 v132; // r9
  __int64 n22129; // rax
  __int64 v134; // rcx
  __int64 v135; // rdi
  __int64 v136; // r8
  __int64 v137; // r9
  __int64 (__fastcall *v138)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v139; // rax
  __int64 v140; // rcx
  __int64 v142; // rdi
  __int64 v144; // rsi
  __int64 v146; // rsi
  __int64 v148; // rdi
  unsigned __int64 v150; // r10
  __int64 v151; // rdx
  __int64 v152; // rbx
  __int64 v153; // rbp
  _QWORD *v154; // r13
  __int64 v155; // r14
  unsigned __int64 v158; // r10
  __int64 v159; // [rsp-198h] [rbp-198h]
  __int64 v160; // [rsp-180h] [rbp-180h]
  __int64 v161; // [rsp-170h] [rbp-170h]
  __int64 v162; // [rsp-168h] [rbp-168h]
  __int64 v163; // [rsp-100h] [rbp-100h]
  __int64 v164; // [rsp-F8h] [rbp-F8h]
  __int64 v165; // [rsp-E8h] [rbp-E8h]
  __int64 v166; // [rsp-D8h] [rbp-D8h]
  __int64 v167; // [rsp-D0h] [rbp-D0h]
  __int64 v168; // [rsp-A0h] [rbp-A0h]
  __int64 v169; // [rsp-98h] [rbp-98h]
  __int64 v170; // [rsp-90h] [rbp-90h]
  __int64 v171; // [rsp-88h] [rbp-88h]
  __int64 v172; // [rsp-80h] [rbp-80h]
  __int64 v173; // [rsp-78h] [rbp-78h]
  __int64 v174; // [rsp-70h] [rbp-70h]
  __int64 v175; // [rsp-68h] [rbp-68h]
  __int64 v176; // [rsp-60h] [rbp-60h]
  __int64 v177; // [rsp-58h] [rbp-58h]

LABEL_1:
  *(_DWORD *)(_RDX - 1) = 1301;
  __asm { vmovsd  qword ptr [rdx+3], xmm15 }
LABEL_84:
  v86 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  *(_QWORD *)(v153 - 112) = v86(
                              *(_QWORD *)(v153 - 56),
                              *(_QWORD *)(v153 - 32),
                              v155 + 17,
                              v86,
                              _RDX,
                              a6,
                              0x310010676ADLL,
                              11368,
                              v152,
                              _RDX,
                              4294957022LL);
  v87 = *(_QWORD *)(v153 - 48);
  v88 = v155 + *(unsigned int *)(v87 + 99);
  v89 = *(_QWORD *)(v153 - 40);
  v90 = v155 + *(unsigned int *)(v87 + 103);
  v91 = v155 + *(unsigned int *)(v87 + 95);
  v92 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
  v93 = v92(v89, *(_QWORD *)(v153 - 32), v155 + 17, v92, v90, v91, 0x310010676ADLL, v91, v88, v90, 4294965744LL);
  *(_QWORD *)(v153 - 120) = v93;
  v97 = *(_QWORD *)(v153 - 112);
  if ( (v97 & 1) == 0 || *(_DWORD *)(v97 - 1) > 0x425u )
    goto LABEL_195;
  if ( (v93 & 1) == 0 || *(_DWORD *)(v93 - 1) > 0x425u )
    goto LABEL_196;
  n28205697 = MEMORY[0xFFFFFFFFA00AC040](v89, 0x3100106770DLL);
  if ( (_DWORD)n28205697 != 28205697
    && ((n28205697 & 1) == 0
     || *(_DWORD *)(n28205697 - 1) > 0x425u
     || *(_DWORD *)(n28205697 + 7) != 11
     || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
  {
    goto LABEL_197;
  }
  if ( (unsigned int)*(_QWORD *)(v153 - 88) != 19270093 )
    goto LABEL_198;
  v8 = 0x310012609CDLL;
  v101 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, _QWORD, __int64, _QWORD))(v154[84] + 16 * ((unsigned int)&unk_26B800 >> 8));
  v101(
    0x310012609CDLL,
    0x3100155D799LL,
    v155 + 17,
    v101,
    v99,
    v100,
    *(_QWORD *)(v153 - 104),
    0x31001ED8925LL,
    *(_QWORD *)(v153 + 24));
  v102 = *(_QWORD *)(v153 - 128);
  v60 = __OFADD__(v102, v102);
  v103 = (unsigned int)(2 * v102);
  if ( v60 )
  {
    __asm { vcvtsi2sd xmm15, xmm15, eax }
    v158 = v154[10] + 12LL;
    if ( v158 >= v154[11] )
    {
      sub_185FA3(v25, v24);
    }
    else
    {
      v154[10] = v158;
      sub_185DD4(v25, v24);
    }
    return;
  }
  while ( 1 )
  {
    *(_QWORD *)(v153 - 96) = v103;
    v104 = MEMORY[0x31001B1CE84] < 591;
    MEMORY[0x31001B1CE84] -= 591;
    if ( v104 )
    {
      MEMORY[0xFFFFFFFFA00ABBC0](v8, 0x3100106770DLL, v24, v25, v26, v27, *(_QWORD *)(v153 - 16), v103, 0x31001B1CE79LL);
      v103 = v172;
    }
    *(_QWORD *)(v153 - 80) = v103;
    v8 = 0x3100109048DLL;
    v9 = 0x3100106770DLL;
    v174 = *(_QWORD *)(v153 - 72);
    v10 = MEMORY[0xFFFFFFFFA008DD80](0x3100109048DLL, 0x3100106770DLL, v155 + 17);
    *(_QWORD *)(v153 - 88) = v10;
    if ( (v10 & 1) == 0 || *(_DWORD *)(v10 - 1) < (unsigned int)&unk_1A0000 )
    {
      MEMORY[0xFFFFFFFFA00ABBC0](0x3100109048DLL, *(_QWORD *)(v153 - 32));
      MEMORY[0xFFFFFFFFA00ABBC0](0x3100109048DLL);
      __debugbreak();
    }
    if ( (v10 & 1) == 0 || *(_DWORD *)(v10 - 1) != 17251549 )
    {
      ((void (*)(void))*(v154 - 5))();
LABEL_174:
      ((void (*)(void))*(v154 - 5))();
LABEL_175:
      ((void (*)(void))*(v154 - 5))();
LABEL_176:
      ((void (*)(void))*(v154 - 5))();
LABEL_177:
      ((void (*)(void))*(v154 - 5))();
LABEL_178:
      ((void (__fastcall *)(__int64, __int64, __int64))*(v154 - 5))(v8, v9, v32);
LABEL_179:
      ((void (__fastcall *)(__int64, __int64, __int64))*(v154 - 5))(v8, v9, v32);
LABEL_180:
      ((void (*)(void))*(v154 - 5))();
LABEL_181:
      ((void (*)(void))*(v154 - 5))();
LABEL_182:
      ((void (*)(void))*(v154 - 5))();
LABEL_183:
      ((void (*)(void))*(v154 - 5))();
LABEL_184:
      ((void (*)(void))*(v154 - 5))();
LABEL_185:
      ((void (*)(void))*(v154 - 5))();
LABEL_186:
      ((void (*)(void))*(v154 - 5))();
LABEL_187:
      ((void (*)(void))*(v154 - 5))();
LABEL_188:
      ((void (__fastcall *)(__int64, __int64, __int64))*(v154 - 5))(v8, v9, v63);
LABEL_189:
      ((void (*)(void))*(v154 - 5))();
LABEL_190:
      ((void (*)(void))*(v154 - 5))();
LABEL_191:
      ((void (*)(void))*(v154 - 5))();
LABEL_192:
      ((void (*)(void))*(v154 - 5))();
LABEL_193:
      ((void (*)(void))*(v154 - 5))();
LABEL_194:
      ((void (*)(void))*(v154 - 5))();
LABEL_195:
      ((void (*)(void))*(v154 - 5))();
LABEL_196:
      ((void (__stdcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))*(v154 - 5))(
        v97,
        v94,
        v95,
        v96,
        v168,
        v169,
        v170,
        v171,
        v172,
        v173,
        v174,
        v175,
        v176,
        v177);
LABEL_197:
      ((void (*)(void))*(v154 - 5))();
LABEL_198:
      ((void (*)(void))*(v154 - 5))();
LABEL_199:
      ((void (*)(void))*(v154 - 5))();
LABEL_200:
      ((void (*)(void))*(v154 - 5))();
LABEL_201:
      ((void (*)(void))*(v154 - 5))();
LABEL_202:
      ((void (*)(void))*(v154 - 5))();
LABEL_203:
      ((void (*)(void))*(v154 - 5))();
LABEL_204:
      ((void (*)(void))*(v154 - 5))();
LABEL_205:
      ((void (*)(void))*(v154 - 5))();
LABEL_206:
      ((void (*)(void))*(v154 - 5))();
LABEL_207:
      ((void (*)(void))*(v154 - 5))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      JUMPOUT(0x18612E);
    }
    n113 = v155 + *(unsigned int *)(v10 + 15);
    if ( (n113 & 1) == 0 )
    {
      if ( (_DWORD)n113 )
        break;
      goto LABEL_13;
    }
    if ( (unsigned int)n113 >= 0x71 )
    {
      if ( (_DWORD)n113 == 113 )
        break;
      n1301 = v155 + *(_DWORD *)(n113 - 1);
      if ( n1301 == 1301 )
      {
        __asm
        {
          vxorpd  xmm15, xmm15, xmm15
          vucomisd xmm15, qword ptr [rcx+3]
        }
        goto LABEL_13;
      }
      if ( n1301 != 1341 || (*(_DWORD *)(n113 + 3) & 0xFFFFFF00) != 0 )
        break;
    }
LABEL_13:
    *(_QWORD *)(v153 - 96) = v155 + *(unsigned int *)(v10 + 11);
    v15 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
    *(_QWORD *)(v153 - 88) = v15(
                               *(_QWORD *)(v153 - 40),
                               *(_QWORD *)(v153 - 32),
                               v155 + 17,
                               v15,
                               v11,
                               v12,
                               0x310010676ADLL,
                               23374,
                               22134,
                               v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 11LL),
                               21680);
    v8 = *(_QWORD *)(v153 - 40);
    v9 = *(_QWORD *)(v153 - 32);
    v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
    v19 = v16(
            v8,
            v9,
            v155 + 17,
            v16,
            v17,
            v18,
            0x310010676ADLL,
            20362,
            15236,
            v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 15LL),
            6708);
    *(_QWORD *)(v153 - 104) = v19;
    v20 = *(_QWORD *)(v153 - 88);
    if ( (v20 & 1) == 0 || *(_DWORD *)(v20 - 1) > 0x425u )
      goto LABEL_174;
    if ( (v19 & 1) == 0 || *(_DWORD *)(v19 - 1) > 0x425u )
      goto LABEL_175;
    v9 = 0x3100106770DLL;
    v21 = MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
    if ( (_DWORD)v21 != (_DWORD)byte_21B349
      && ((v21 & 1) == 0
       || *(_DWORD *)(v21 - 1) > 0x425u
       || *(_DWORD *)(v21 + 7) != 11
       || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
    {
      goto LABEL_176;
    }
    v22 = *(_QWORD *)(v153 - 96);
    if ( (v22 & 1) == 0 || *(_DWORD *)(v22 - 1) != 28334745 )
      goto LABEL_177;
    v9 = 0x3100106770DLL;
    n0x71 = MEMORY[0xFFFFFFFF9FFF77C0](v8, 0x3100106770DLL, 0x7FF628BC5DB0LL, 0);
    if ( (n0x71 & 1) != 0 )
    {
      if ( (unsigned int)n0x71 < 0x71 )
        goto LABEL_29;
      if ( (_DWORD)n0x71 == 113 )
        goto LABEL_95;
      n1301_1 = v155 + *(_DWORD *)(n0x71 - 1);
      if ( n1301_1 == 1301 )
      {
        __asm
        {
          vxorpd  xmm15, xmm15, xmm15
          vucomisd xmm15, qword ptr [rax+3]
        }
LABEL_29:
        n113_1 = *(_QWORD *)(v153 + 24);
        if ( (n113_1 & 1) != 0 )
        {
          if ( (unsigned int)n113_1 >= 0x71 )
          {
            if ( (_DWORD)n113_1 == 113 )
              goto LABEL_34;
            n1341 = v155 + *(_DWORD *)(n113_1 - 1);
            if ( n1341 == 1301 )
            {
              __asm
              {
                vxorpd  xmm15, xmm15, xmm15
                vucomisd xmm15, qword ptr [rax+3]
              }
            }
            else if ( n1341 != 1341 || (*(_DWORD *)(n113_1 + 3) & 0xFFFFFF00) != 0 )
            {
LABEL_34:
              v31 = *(_QWORD *)(v153 - 48);
              v32 = v155 + *(unsigned int *)(v31 + 19);
              v33 = v155 + *(unsigned int *)(v31 + 23);
              v8 = *(unsigned int *)(v31 + 27);
              v9 = (unsigned int)((int)v8 >> 1);
              if ( !(_DWORD)v9 )
                goto LABEL_178;
              v9 = (unsigned int)-(int)v9;
              if ( __OFSUB__((_DWORD)v9, 1) )
                goto LABEL_178;
              v34 = *(int *)(v31 + 31) >> 1;
              if ( !v34 )
                goto LABEL_179;
              v35 = (unsigned int)-v34;
              if ( __OFSUB__((_DWORD)v35, 1) )
                goto LABEL_179;
              v36 = (unsigned int)(2 * v9);
              if ( __OFADD__((_DWORD)v9, (_DWORD)v9) )
              {
                __asm { vcvtsi2sd xmm15, xmm15, esi }
                v142 = v154[10];
                if ( (unsigned __int64)(v142 + 12) >= v154[11] )
                {
                  sub_185E95(v142, v9, v32, v31, v35);
                }
                else
                {
                  v154[10] = v142 + 12;
                  sub_185BBA(v142 + 1);
                }
                return;
              }
              v37 = (unsigned int)(2 * v35);
              if ( __OFADD__((_DWORD)v35, (_DWORD)v35) )
              {
                __asm { vcvtsi2sd xmm15, xmm15, r8d }
                v144 = v154[10];
                if ( (unsigned __int64)(v144 + 12) >= v154[11] )
                {
                  sub_185EC6(v36, v144, v32, v31, v35);
                }
                else
                {
                  v154[10] = v144 + 12;
                  sub_185BEE(v36, v144 + 1);
                }
                return;
              }
              v38 = v36;
              v8 = *(_QWORD *)(v153 - 40);
              v39 = v37;
              v9 = *(_QWORD *)(v153 - 32);
              v165 = v155 + *(unsigned int *)(v31 + 19);
              v40 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
              v41 = v40(v8, v9, v155 + 17, v40, v38, v39, 0x310010676ADLL, v165, v33, v38, v39);
              if ( (v41 & 1) == 0 || *(_DWORD *)(v41 - 1) > 0x425u )
                goto LABEL_180;
              *(_QWORD *)(v153 - 104) = MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
              v42 = *(_QWORD *)(v153 - 48);
              v8 = *(_QWORD *)(v153 - 56);
              v9 = *(_QWORD *)(v153 - 32);
              v43 = v155 + *(unsigned int *)(v42 + 35);
              v164 = v155 + *(unsigned int *)(v42 + 39);
              v44 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
              v46 = v44(v8, v9, v155 + 17, v44, v43, v45, 0x310010676ADLL, 24466, 17364, v43, v164);
              *(_QWORD *)(v153 - 88) = v46;
              if ( (v46 & 1) == 0 || *(_DWORD *)(v46 - 1) > 0x425u )
                goto LABEL_181;
              v9 = 0x3100106770DLL;
              n23425149 = MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
              if ( (_DWORD)n23425149 != 23425149
                && ((n23425149 & 1) == 0
                 || *(_DWORD *)(n23425149 - 1) > 0x425u
                 || *(_DWORD *)(n23425149 + 7) != 20
                 || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
              {
                goto LABEL_182;
              }
              v9 = 0x3100106770DLL;
              MEMORY[0xFFFFFFFF9FFF77C0](v8, 0x3100106770DLL, 0x7FF62AF86780LL, 1);
              goto LABEL_61;
            }
          }
        }
        else if ( (_DWORD)n113_1 )
        {
          goto LABEL_34;
        }
        v49 = *(_QWORD *)(v153 - 48);
        v50 = *(int *)(v49 + 43) >> 1;
        if ( !v50 )
          goto LABEL_183;
        v51 = (unsigned int)-v50;
        if ( __OFSUB__((_DWORD)v51, 1) )
          goto LABEL_183;
        if ( __OFADD__((_DWORD)v51, (_DWORD)v51) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, edx }
          v146 = v154[10];
          if ( (unsigned __int64)(v146 + 12) >= v154[11] )
          {
            sub_185EF5(v49, v51);
          }
          else
          {
            v154[10] = v146 + 12;
            sub_185C4B(v8, v146 + 1);
          }
          return;
        }
        v8 = *(_QWORD *)(v153 - 40);
        v9 = *(_QWORD *)(v153 - 32);
        v167 = v155 + *(unsigned int *)(v49 + 47);
        v52 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
        v53 = v52(
                v8,
                v9,
                v155 + 17,
                v52,
                (unsigned int)(2 * v51),
                v27,
                0x310010676ADLL,
                (unsigned int)(2 * v51),
                4890,
                5936,
                v167);
        *(_QWORD *)(v153 - 88) = v53;
        if ( (v53 & 1) == 0 || *(_DWORD *)(v53 - 1) > 0x425u )
          goto LABEL_184;
        MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
        v9 = 0x3100106770DLL;
        n23425149_1 = MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
        if ( (_DWORD)n23425149_1 != 23425149
          && ((n23425149_1 & 1) == 0
           || *(_DWORD *)(n23425149_1 - 1) > 0x425u
           || *(_DWORD *)(n23425149_1 + 7) != 20
           || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
        {
          goto LABEL_185;
        }
        v57 = v154[10];
        if ( (unsigned __int64)(v57 + 16) >= v154[11] )
        {
          v8 = MEMORY[0xFFFFFFFF9FFF7E80](v57, 0x3100106770DLL, 16);
        }
        else
        {
          v154[10] = v57 + 16;
          v8 = v57 + 1;
        }
        *(_DWORD *)(v8 - 1) = 32771877;
        *(_DWORD *)(v8 + 3) = v155 + 2021;
        *(_DWORD *)(v8 + 7) = v155 + 2021;
        *(_DWORD *)(v8 + 11) = v155 + 720893;
        *(_DWORD *)(v8 + 11) = v155 + 113;
        v9 = 0x3100106770DLL;
        MEMORY[0xFFFFFFFF9FFF77C0](
          v8,
          0x3100106770DLL,
          *(_QWORD *)((char *)&loc_184E66 + 2),
          2,
          v55,
          v56,
          *(_QWORD *)(v153 - 96),
          v155 + 113,
          v8);
LABEL_61:
        v58 = *(_QWORD *)(v153 - 80);
        if ( (v58 & 1) != 0 )
          goto LABEL_186;
        v59 = (int)v58 >> 1;
        v60 = __OFADD__(1, v59);
        v61 = v59 + 1;
        if ( v60 )
          goto LABEL_187;
        *(_QWORD *)(v153 - 128) = v61;
        v62 = *(_QWORD *)(v153 - 48);
        v63 = v155 + *(unsigned int *)(v62 + 59);
        v64 = v155 + *(unsigned int *)(v62 + 63);
        v8 = *(unsigned int *)(v62 + 67);
        v9 = (unsigned int)((int)v8 >> 1);
        if ( !(_DWORD)v9 )
          goto LABEL_188;
        v9 = (unsigned int)-(int)v9;
        if ( __OFSUB__((_DWORD)v9, 1) )
          goto LABEL_188;
        if ( __OFADD__((_DWORD)v9, (_DWORD)v9) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, esi }
          v148 = v154[10];
          if ( (unsigned __int64)(v148 + 12) >= v154[11] )
          {
            sub_185F20(v148, v9, v63, v62, v48);
          }
          else
          {
            v154[10] = v148 + 12;
            sub_185CBB(v148 + 1);
          }
          return;
        }
        v65 = v155 + *(unsigned int *)(v62 + 59);
        v66 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64, _QWORD))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
        *(_QWORD *)(v153 - 88) = v66(
                                   *(_QWORD *)(v153 - 56),
                                   *(_QWORD *)(v153 - 32),
                                   v155 + 17,
                                   v66,
                                   (unsigned int)(2 * v9),
                                   v65,
                                   0x310010676ADLL,
                                   6432,
                                   v65,
                                   v64,
                                   (unsigned int)(2 * v9));
        v67 = *(_QWORD *)(v153 - 48);
        v68 = *(_QWORD *)(v153 - 40);
        v69 = v155 + *(unsigned int *)(v67 + 71);
        v162 = v155 + *(unsigned int *)(v67 + 75);
        v70 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
        v72 = v70(
                v68,
                *(_QWORD *)(v153 - 32),
                v155 + 17,
                v70,
                v69,
                v71,
                0x310010676ADLL,
                v69,
                v162,
                10538,
                4294966468LL);
        *(_QWORD *)(v153 - 104) = v72;
        v73 = *(_QWORD *)(v153 - 88);
        if ( (v73 & 1) == 0 || *(_DWORD *)(v73 - 1) > 0x425u )
          goto LABEL_189;
        if ( (v72 & 1) == 0 || *(_DWORD *)(v72 - 1) > 0x425u )
          goto LABEL_190;
        n18536041 = MEMORY[0xFFFFFFFFA00AC040](v68, 0x3100106770DLL);
        if ( (_DWORD)n18536041 != 18536041
          && ((n18536041 & 1) == 0
           || *(_DWORD *)(n18536041 - 1) > 0x425u
           || *(_DWORD *)(n18536041 + 7) != 11
           || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
        {
          goto LABEL_191;
        }
        *(_QWORD *)(v153 - 104) = MEMORY[0xFFFFFFFF9FFF77C0](v68, 0x3100106770DLL, 0x7FF6287EAE50LL, 0);
        v75 = *(_QWORD *)(v153 - 48);
        v76 = *(_QWORD *)(v153 - 40);
        v77 = v155 + *(unsigned int *)(v75 + 79);
        v159 = v155 + *(unsigned int *)(v75 + 83);
        v78 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
        v80 = v78(v76, *(_QWORD *)(v153 - 32), v155 + 17, v78, v77, v79, 0x310010676ADLL, v77, v159, 7290, 29354);
        if ( (_DWORD)v80 != (_DWORD)byte_238D5D
          && ((v80 & 1) == 0
           || *(_DWORD *)(v80 - 1) > 0x425u
           || *(_DWORD *)(v80 + 7) != 4
           || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
        {
          goto LABEL_192;
        }
        *(_QWORD *)(v153 - 88) = MEMORY[0xFFFFFFFFA0046FC0](v76, *(_QWORD *)(v153 - 32), *(_QWORD *)(v153 - 104), 208);
        v81 = *(_QWORD *)(v153 - 48);
        v82 = *(int *)(v81 + 87) >> 1;
        if ( !v82 )
          goto LABEL_193;
        v83 = (unsigned int)-v82;
        if ( __OFSUB__((_DWORD)v83, 1) )
          goto LABEL_193;
        v84 = *(int *)(v81 + 91) >> 1;
        if ( !v84 )
          goto LABEL_194;
        v85 = -v84;
        if ( __OFSUB__(v85, 1) )
          goto LABEL_194;
        v152 = (unsigned int)(2 * v83);
        if ( __OFADD__((_DWORD)v83, (_DWORD)v83) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, edx }
          v150 = v154[10] + 12LL;
          if ( v150 >= v154[11] )
          {
            sub_185F4D(v81, v83);
          }
          else
          {
            v154[10] = v150;
            sub_185D44();
          }
          return;
        }
        _RDX = (unsigned int)(2 * v85);
        if ( __OFADD__(v85, v85) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, esi }
          v151 = v154[10];
          if ( (unsigned __int64)(v151 + 12) >= v154[11] )
          {
            sub_185F78(v81, v151);
            return;
          }
          v154[10] = v151 + 12;
          _RDX = v151 + 1;
          goto LABEL_1;
        }
        goto LABEL_84;
      }
      if ( n1301_1 == 1341 && (*(_DWORD *)(n0x71 + 3) & 0xFFFFFF00) == 0 )
        goto LABEL_29;
    }
    else if ( !(_DWORD)n0x71 )
    {
      goto LABEL_29;
    }
LABEL_95:
    v103 = *(_QWORD *)(v153 - 80);
  }
  v105 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
  *(_QWORD *)(v153 - 72) = v105(
                             *(_QWORD *)(v153 - 40),
                             *(_QWORD *)(v153 - 32),
                             v155 + 17,
                             v105,
                             v11,
                             v12,
                             0x310010676ADLL,
                             v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 143LL),
                             v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 147LL),
                             14602,
                             18554);
  v106 = *(_QWORD *)(v153 - 56);
  v107 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  v110 = v107(
           v106,
           *(_QWORD *)(v153 - 32),
           v155 + 17,
           v107,
           v108,
           v109,
           0x310010676ADLL,
           11268,
           22500,
           26240,
           v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 151LL));
  v111 = *(_QWORD *)(v153 - 72);
  if ( (v111 & 1) == 0 || *(_DWORD *)(v111 - 1) > 0x425u )
    goto LABEL_199;
  if ( (v110 & 1) == 0 || *(_DWORD *)(v110 - 1) > 0x425u )
    goto LABEL_200;
  *(_QWORD *)(v153 - 96) = MEMORY[0xFFFFFFFFA00AC040](v106, 0x3100106770DLL);
  v112 = *(_QWORD *)(v153 - 48);
  v113 = *(_QWORD *)(v153 - 40);
  v114 = v155 + *(unsigned int *)(v112 + 155);
  v166 = v155 + *(unsigned int *)(v112 + 159);
  v115 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
  v117 = v115(v113, *(_QWORD *)(v153 - 32), v155 + 17, v115, v114, v116, 0x310010676ADLL, v114, v166, 15624, 30508);
  if ( (v117 & 1) == 0 || *(_DWORD *)(v117 - 1) > 0x425u )
    goto LABEL_201;
  *(_QWORD *)(v153 - 72) = MEMORY[0xFFFFFFFFA00AC040](v113, 0x3100106770DLL);
  v118 = *(_QWORD *)(v153 - 48);
  v119 = *(_QWORD *)(v153 - 56);
  v120 = v155 + *(unsigned int *)(v118 + 163);
  v163 = v155 + *(unsigned int *)(v118 + 167);
  v121 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  v123 = v121(v119, *(_QWORD *)(v153 - 32), v155 + 17, v121, v120, v122, 0x310010676ADLL, v120, v163, 12976, 12762);
  if ( (v123 & 1) == 0 || *(_DWORD *)(v123 - 1) > 0x425u )
    goto LABEL_202;
  MEMORY[0xFFFFFFFFA00AC040](v119, 0x3100106770DLL);
  MEMORY[0xFFFFFFFFA00AC040](v119, 0x3100106770DLL);
  *(_QWORD *)(v153 - 72) = MEMORY[0xFFFFFFFFA0102840](v119, *(_QWORD *)(v153 - 32));
  v124 = *(_QWORD *)(v153 - 56);
  v125 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  v128 = v125(
           v124,
           *(_QWORD *)(v153 - 32),
           v155 + 17,
           v125,
           v126,
           v127,
           0x310010676ADLL,
           1998,
           4034,
           4294962518LL,
           v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 171LL));
  *(_QWORD *)(v153 - 96) = v128;
  if ( (v128 & 1) == 0 || *(_DWORD *)(v128 - 1) > 0x425u )
    goto LABEL_203;
  MEMORY[0xFFFFFFFFA00AC040](v124, 0x3100106770DLL);
  v129 = *(_QWORD *)(v153 - 72);
  if ( (v129 & 1) == 0 || *(_DWORD *)(v129 - 1) > 0x425u )
    goto LABEL_204;
  *(_QWORD *)(v153 - 96) = MEMORY[0xFFFFFFFFA00AC040](v124, 0x3100106770DLL);
  v130 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  n22129 = v130(
             *(_QWORD *)(v153 - 56),
             *(_QWORD *)(v153 - 32),
             v155 + 17,
             v130,
             v131,
             v132,
             0x310010676ADLL,
             4294964328LL,
             3012,
             v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 175LL),
             4294964220LL);
  if ( (_DWORD)n22129 != 22129
    && ((n22129 & 1) == 0
     || *(_DWORD *)(n22129 - 1) > 0x425u
     || *(_DWORD *)(n22129 + 7) != 4
     || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
  {
    goto LABEL_205;
  }
  MEMORY[0xFFFFFFFFA008D940](0x31001094899LL, 0x3100106770DLL, v155 + 17);
  *(_QWORD *)(v153 - 56) = MEMORY[0xFFFFFFFFA0102840](0x31001094899LL, *(_QWORD *)(v153 - 32));
  v134 = *(_QWORD *)(v153 - 48);
  v135 = *(_QWORD *)(v153 - 40);
  v136 = v155 + *(unsigned int *)(v134 + 187);
  v137 = v155 + *(unsigned int *)(v134 + 179);
  v161 = v155 + *(unsigned int *)(v134 + 191);
  v160 = v155 + *(unsigned int *)(v134 + 183);
  v138 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
  v139 = v138(v135, *(_QWORD *)(v153 - 32), v155 + 17, v138, v136, v137, 0x310010676ADLL, v137, v160, v136, v161);
  *(_QWORD *)(v153 - 48) = v139;
  if ( (v139 & 1) == 0 || *(_DWORD *)(v139 - 1) > 0x425u )
    goto LABEL_206;
  MEMORY[0xFFFFFFFFA00AC040](v135, 0x3100106770DLL);
  v140 = *(_QWORD *)(v153 - 56);
  if ( (v140 & 1) == 0 || *(_DWORD *)(v140 - 1) > 0x425u )
    goto LABEL_207;
  MEMORY[0xFFFFFFFFA00AC040](v135, 0x3100106770DLL);
  MEMORY[0xFFFFFFFFA0102840](v135, *(_QWORD *)(v153 - 32));
  (*(void (__fastcall **)(__int64, __int64, __int64))(v154[84] + 315968LL))(0x31001D635A1LL, 0x310020349D9LL, v155 + 17);
  v104 = MEMORY[0x31001B1CE84] < 1142;
  MEMORY[0x31001B1CE84] -= 1142;
  if ( v104 )
    MEMORY[0xFFFFFFFFA00ABBC0](0x31001D635A1LL, 0x3100106770DLL);
}


//==== sub_185DD4 @ 0x185dd4
void __fastcall sub_185DD4()
{
  *(_DWORD *)(_RBX - 1) = 1301;
  __asm { vmovsd  qword ptr [rbx+3], xmm15 }
  JUMPOUT(0x185411);
}


//==== sub_185E95 @ 0x185e95
void __fastcall sub_185E95(__int64 a1, __int64 a2)
{
  __int64 _RDI; // rax

  __asm { vmovsd  [rsp+30h+var_30], xmm15 }
  _RDI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+30h+var_30] }
  sub_185BBA(_RDI);
}


//==== sub_185EC6 @ 0x185ec6
void __fastcall sub_185EC6(__int64 a1, __int64 a2)
{
  __int64 _RSI; // rax

  __asm { vmovsd  [rsp+30h+var_30], xmm15 }
  _RSI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+30h+var_30] }
  sub_185BEE(a1, _RSI);
}


//==== sub_185EF5 @ 0x185ef5
void __fastcall sub_185EF5(__int64 a1, __int64 a2)
{
  __int64 _RSI; // rax

  __asm { vmovsd  [rsp+20h+var_20], xmm15 }
  _RSI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+20h+var_20] }
  sub_185C4B(a1, _RSI);
}


//==== sub_185F20 @ 0x185f20
void __fastcall sub_185F20(__int64 a1, __int64 a2)
{
  __int64 _RDI; // rax

  __asm { vmovsd  [rsp+28h+var_28], xmm15 }
  _RDI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+28h+var_28] }
  sub_185CBB(_RDI);
}


//==== sub_185F4D @ 0x185f4d
void __fastcall sub_185F4D(__int64 a1, __int64 a2)
{
  __asm { vmovsd  [rsp+20h+var_20], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+20h+var_20] }
  sub_185D44();
}


//==== sub_185F78 @ 0x185f78
void __fastcall sub_185F78(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 _RDX; // rax
  __int64 v11; // r8
  __int64 v12; // r9

  __asm { vmovsd  [rsp+20h+var_20], xmm15 }
  _RDX = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+20h+var_20] }
  sub_185D77(a1, a2, _RDX, a4, v11, v12, a7, a8);
}


//==== sub_185FA3 @ 0x185fa3
void __fastcall sub_185FA3(__int64 a1, __int64 a2)
{
  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+8+var_8] }
  sub_185DD4();
}


//==== sub_1932B0 @ 0x1932b0
__int64 __fastcall sub_1932B0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48,
        __int64 a49)
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)(
           a4,
           a3,
           a5,
           a6,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48);
}


//==== sub_195BCE @ 0x195bce
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_195BCE(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  unsigned int n0x3FFFFFFF; // eax
  __int64 v10; // rbp
  _QWORD *v11; // r13
  __int64 v12; // r14
  void (__fastcall *v14)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, __int64); // rcx
  bool v15; // cc
  unsigned __int64 v18; // r10

  *(_QWORD *)(v10 - 56) = n0x3FFFFFFF;
  if ( n0x3FFFFFFF > 0x3FFFFFFF )
  {
    __asm { vcvtsi2sd xmm15, xmm15, r10 }
    v18 = v11[10] + 12LL;
    if ( v18 >= v11[11] )
    {
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64, __int64))sub_195E00)(
               a1,
               a2,
               n0x3FFFFFFF,
               a4,
               a5,
               a6);
    }
    else
    {
      v11[10] = v18;
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64, __int64))sub_195DC7)(
               a1,
               a2,
               n0x3FFFFFFF,
               a4,
               a5,
               a6);
    }
  }
  else
  {
    v14 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, __int64))(v11[84] + 16 * ((unsigned int)qword_1B2100 >> 8));
    v14(
      0x31001108C55LL,
      0x31001108431LL,
      v12 + 17,
      v14,
      a5,
      a6,
      v12 + 17,
      a4,
      2 * n0x3FFFFFFF,
      310411480,
      0,
      0x3100101F69DLL);
    v15 = MEMORY[0x31001F62990] < 149;
    MEMORY[0x31001F62990] -= 149;
    if ( v15 )
      MEMORY[0xFFFFFFFFA00ABBC0](0x31001108C55LL, 0x3100106770DLL);
    return v12 + 17;
  }
}


//==== sub_195D8A @ 0x195d8a
__int64 __fastcall sub_195D8A(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // r8
  __int64 v13; // r9

  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  MEMORY[0xFFFFFFFFA00ADB80](a1);
  return sub_195BCE(a1, a2, v10, v11, v12, v13, a7, a8, a9);
}


//==== sub_195DC7 @ 0x195dc7
void __fastcall sub_195DC7(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  *(_DWORD *)(_RAX - 1) = 1301;
  __asm { vmovsd  qword ptr [rax+3], xmm15 }
  JUMPOUT(0x195BE3);
}


//==== sub_195E00 @ 0x195e00
void __fastcall sub_195E00(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v11; // r8
  __int64 v12; // r9
  __int64 v15; // [rsp+10h] [rbp-8h]

  __asm { vmovsd  [rsp+18h+var_18], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+18h+var_18] }
  sub_195DC7(a1, a2, a3, v15, v11, v12, a7, a8, a9);
}


//==== nullsub_8 @ 0x195ef4
void nullsub_8()
{
  __asm { iretd }
}


//==== sub_1A6DF0 @ 0x1a6df0
__int64 __fastcall sub_1A6DF0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48)
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)(
           a4,
           a3,
           a5,
           a6,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48);
}


//==== sub_1A6EB0 @ 0x1a6eb0
__int64 __fastcall sub_1A6EB0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48)
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)(
           a4,
           a3,
           a5,
           a6,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43,
           a44,
           a45,
           a46,
           a47,
           a48);
}


//==== sub_1A7030 @ 0x1a7030
__int64 sub_1A7030()
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)();
}


//==== sub_1A897D @ 0x1a897d
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_1A897D(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  int v9; // eax
  __int64 v10; // rbp
  __int64 v11; // r13
  int v13; // ecx
  bool v14; // of
  int v15; // eax
  bool v16; // cc
  __int64 v19; // rcx
  __int64 v20; // [rsp-20h] [rbp-20h]

  v13 = 32 * a4;
  v14 = __OFSUB__(v9, v13);
  v15 = v9 - v13;
  if ( v14 )
  {
    (*(void (**)(void))(v11 - 40))();
    (*(void (**)(void))(v11 - 32))();
    JUMPOUT(0x1A8A81);
  }
  v16 = MEMORY[0x3100171ADA0] < 34;
  MEMORY[0x3100171ADA0] -= 34;
  if ( v16 )
  {
    a2 = 0x3100106770DLL;
    v20 = *(_QWORD *)(v10 - 16);
    MEMORY[0xFFFFFFFFA00ABBC0](a1, 0x3100106770DLL);
    v15 = v20;
  }
  if ( !__OFADD__(v15, v15) )
    return (unsigned int)(2 * v15);
  __asm { vcvtsi2sd xmm15, xmm15, eax }
  v19 = *(_QWORD *)(v11 + 80);
  if ( (unsigned __int64)(v19 + 12) >= *(_QWORD *)(v11 + 88) )
    return ((__int64 (__stdcall *)(__int64, __int64, __int64))sub_1A8A3B)(v19, a3, a5);
  *(_QWORD *)(v11 + 80) = v19 + 12;
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64))sub_1A8A26)(
           a1,
           a2,
           a3,
           v19 + 1,
           a5,
           a6,
           a7);
}


//==== sub_1A89CA @ 0x1a89ca
__int64 __fastcall sub_1A89CA(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v10; // rdx
  __int64 v11; // r8
  __int64 v12; // r9
  __int64 v14; // [rsp+0h] [rbp-8h]

  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  MEMORY[0xFFFFFFFFA00ADB80]();
  return sub_1A897D(a1, a2, v10, v14, v11, v12, a7, a8, a9);
}


//==== sub_1A8A26 @ 0x1a8a26
void __fastcall sub_1A8A26(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 _RCX,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  *(_DWORD *)(_RCX - 1) = 1301;
  __asm { vmovsd  qword ptr [rcx+3], xmm15 }
  JUMPOUT(0x1A89A9);
}


//==== sub_1A8A3B @ 0x1a8a3b
void __fastcall sub_1A8A3B(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 _RCX; // rax
  __int64 v12; // rdx
  __int64 v13; // r8
  __int64 v14; // r9

  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  _RCX = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+8+var_8] }
  sub_1A8A26(a1, a2, v12, _RCX, v13, v14, a7, a8, a9);
}


//==== sub_1ACA64 @ 0x1aca64
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_1ACA64(
        double a1,
        __m128 _XMM1,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  char v12; // zf
  char v13; // pf
  __int64 v14; // r13
  bool v19; // of
  __int64 result; // rax
  __int64 v21; // rax

  __asm
  {
    vcvttpd2dq xmm15, xmm1
    vcvtdq2pd xmm15, xmm15
    vucomisd xmm15, xmm1
  }
  if ( v13 )
    goto LABEL_7;
  if ( !v12 )
    goto LABEL_7;
  __asm { vcvttsd2si eax, xmm1 }
  if ( !_EAX )
  {
    __asm { vpextrd r10d, xmm1, 1 }
    if ( _R10D < 0 )
      goto LABEL_7;
  }
  v19 = __OFADD__(_EAX, _EAX);
  result = (unsigned int)(2 * _EAX);
  if ( v19 )
  {
LABEL_7:
    v21 = *(_QWORD *)(v14 + 80);
    if ( (unsigned __int64)(v21 + 12) >= *(_QWORD *)(v14 + 88) )
    {
      return ((__int64 (__stdcall *)(__int64, __int64, __int64, __int64))sub_1ACDD7)(a6, a5, a7, a8);
    }
    else
    {
      *(_QWORD *)(v14 + 80) = v21 + 12;
      result = v21 + 1;
      *(_DWORD *)(result - 1) = 1301;
      __asm { vmovsd  qword ptr [rax+3], xmm1 }
    }
  }
  return result;
}


//==== sub_1ACDA1 @ 0x1acda1
__int64 __fastcall sub_1ACDA1(
        __int64 a1,
        double a2,
        __m128 _XMM1,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // rbp
  double v13; // xmm0_8
  __m128 _XMM1; // xmm1
  __int64 v15; // rdx
  __int64 v16; // rcx
  __int64 v17; // r8
  __int64 v18; // r9
  __int64 v20; // [rsp+0h] [rbp-10h]

  __asm { vmovsd  [rsp+8+var_8], xmm1 }
  v20 = *(_QWORD *)(v12 - 16);
  v13 = MEMORY[0xFFFFFFFFA00ABBC0](a1, 0x3100106770DLL);
  __asm { vmovsd  xmm1, [rsp+10h+var_10] }
  return sub_1ACA64(v13, _XMM1, a1, 0x3100106770DLL, v15, v16, v17, v18, a9, a10, a11, a12);
}


//==== sub_1ACDD7 @ 0x1acdd7
void __fastcall sub_1ACDD7(
        __int64 a1,
        __int64 a2,
        double a3,
        __m128 _XMM1,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __asm { vmovsd  [rsp+8+var_8], xmm1 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm1, [rsp+8+var_8] }
  JUMPOUT(0x1ACABE);
}


//==== sub_1B43B1 @ 0x1b43b1
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1B43B1(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1B4284 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_1B42FA + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_1B4284 + 2) = **(_QWORD **)((char *)&loc_1B4291 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A733F71LL;
  return result;
}


//==== sub_1B4413 @ 0x1b4413
__int64 __fastcall sub_1B4413(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1B4284 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_1B4284 + 2) = **(_QWORD **)((char *)&loc_1B4291 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_1B9BE6 @ 0x1b9be6
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1B9BE6(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1B9AB9 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_1B9B2F + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_1B9AB9 + 2) = **(_QWORD **)((char *)&loc_1B9AC6 + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A739431LL;
  return result;
}


//==== sub_1B9C48 @ 0x1b9c48
__int64 __fastcall sub_1B9C48(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1B9AB9 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_1B9AB9 + 2) = **(_QWORD **)((char *)&loc_1B9AC6 + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_1B9FCA @ 0x1b9fca
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1B9FCA(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1B9E3F + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_1B9EB5 + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_1B9E3F + 2) = **(_QWORD **)((char *)&loc_1B9E4C + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A739AB1LL;
  return result;
}


//==== sub_1BA02C @ 0x1ba02c
__int64 __fastcall sub_1BA02C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1B9E3F + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_1B9E3F + 2) = **(_QWORD **)((char *)&loc_1B9E4C + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_1BA2FD @ 0x1ba2fd
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1BA2FD(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  MEMORY[0x497400268418] = v5;
  v9 = &v10;
  result = MEMORY[0x7FF628432C00](a1, a2, a5, v8, v6, 0);
  if ( result )
    MEMORY[0x497400268418] = MEMORY[0x497400268408] - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A739EB1LL;
  return result;
}


//==== sub_1BA35F @ 0x1ba35f
__int64 __fastcall sub_1BA35F(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  MEMORY[0x497400268418] = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    MEMORY[0x497400268418] = MEMORY[0x497400268408] - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_1BA9ED @ 0x1ba9ed
// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_1BA9ED(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  _BYTE v8[40]; // [rsp+0h] [rbp-38h] BYREF
  __int64 *v9; // [rsp+28h] [rbp-10h]
  __int64 v10; // [rsp+30h] [rbp-8h] BYREF
  char *retaddr; // [rsp+38h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1BA8C0 + 2) = v5;
  v9 = &v10;
  result = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _BYTE *, __int64, _QWORD))((char *)&loc_1BA936 + 2))(
             a1,
             a2,
             a5,
             v8,
             v6,
             0);
  if ( result )
    **(_QWORD **)((char *)&loc_1BA8C0 + 2) = **(_QWORD **)((char *)&loc_1BA8CD + 2) - *(_QWORD *)(v6 - 72);
  else
    retaddr += 0x7FF68A73A5B1LL;
  return result;
}


//==== sub_1BAA4F @ 0x1baa4f
__int64 __fastcall sub_1BAA4F(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // rbx
  __int64 v6; // rbp
  __int64 result; // rax
  char *retaddr; // [rsp+28h] [rbp+0h]

  retaddr -= a5;
  **(_QWORD **)((char *)&loc_1BA8C0 + 2) = v5;
  result = MEMORY[0x7FF62ACDBC60](a1, a2, a3, 0x49740022C000LL);
  if ( !result )
  {
    result = -1;
    **(_QWORD **)((char *)&loc_1BA8C0 + 2) = **(_QWORD **)((char *)&loc_1BA8CD + 2) - *(_QWORD *)(v6 - 72);
  }
  return result;
}


//==== sub_1BF1C5 @ 0x1bf1c5
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_1BF1C5(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 result; // rax

  *(_DWORD *)(result - 1) = 1301;
  __asm { vmovsd  qword ptr [rax+3], xmm15 }
  return result;
}


//==== sub_1BF1DA @ 0x1bf1da
__int64 __fastcall sub_1BF1DA(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9

  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+8+var_8] }
  return sub_1BF1C5(a1, a2, v11, v12, v13, v14, a7, a8, a9);
}


//==== nullsub_9 @ 0x203874
void nullsub_9()
{
  __asm { iretd }
}


//==== sub_20A063 @ 0x20a063
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_20A063(
        __m128 _XMM0,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  bool v8; // cf
  bool v9; // zf
  bool v10; // pf
  bool v13; // cc
  __int64 n0x1000000; // rax
  __int64 v16; // rbp
  __int64 v17; // r13
  __int64 v18; // r14
  _BYTE *v20; // rax

  *(_DWORD *)(n0x1000000 - 1) = 1301;
  __asm { vmovsd  qword ptr [rax+3], xmm15 }
  MEMORY[0x31002034DA8] = n0x1000000;
  v8 = (unsigned int)n0x1000000 < 0x1000000;
  v9 = (_DWORD)n0x1000000 == 0x1000000;
  v10 = __SETP__(n0x1000000, 0x1000000);
  if ( (unsigned int)n0x1000000 >= 0x1000000 )
  {
    v8 = 0;
    v9 = (n0x1000000 & 1) == 0;
    v10 = __SETP__(n0x1000000 & 1, 0);
    if ( (n0x1000000 & 1) != 0 )
    {
      v8 = 0;
      v9 = (MEMORY[0x31002000000] & 4) == 0;
      v10 = __SETP__(MEMORY[0x31002000000] & 4, 0);
      if ( (MEMORY[0x31002000000] & 4) != 0 )
      {
        v20 = (_BYTE *)((v18 + (unsigned int)n0x1000000) & 0xFFFFFFFFFFFC0000LL);
        v8 = 0;
        v9 = (*v20 & 2) == 0;
        v10 = __SETP__(*v20 & 2, 0);
        if ( (*v20 & 2) != 0 )
          MEMORY[0xFFFFFFFF9FFE7640](0x310020349D9LL, a3, a4, a5, 0x31002034DA8LL);
      }
    }
  }
  _R10 = 0x402E000000000000LL;
  __asm
  {
    vmovq   xmm1, r10
    vucomisd xmm0, xmm1
  }
  if ( !v10 && !v8 && !v9 )
  {
    (*(void (__fastcall **)(__int64, __int64, __int64, _QWORD))(v17 - 40))(
      0x310020349D9LL,
      a3,
      a4,
      *(unsigned int *)(*(_QWORD *)(v16 - 128) + 95LL));
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    (*(void (**)(void))(v17 - 32))();
    JUMPOUT(0x20A2F4);
  }
  v13 = MEMORY[0x31001FB5CF8] < 444;
  MEMORY[0x31001FB5CF8] -= 444;
  if ( v13 )
    MEMORY[0xFFFFFFFFA00ABBC0](0x310020349D9LL, 0x3100106770DLL);
  return *(_QWORD *)(v16 - 80);
}


//==== sub_20A20A @ 0x20a20a
__int64 __fastcall sub_20A20A(
        __int64 a1,
        __int64 a2,
        __m128 _XMM0,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __m128 _XMM0; // xmm0
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9

  __asm
  {
    vmovsd  [rsp+10h+var_10], xmm0
    vmovsd  [rsp+10h+var_8], xmm15
  }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm
  {
    vmovsd  xmm0, [rsp+10h+var_10]
    vmovsd  xmm15, [rsp+10h+var_8]
  }
  return sub_20A063(_XMM0, a1, a2, v11, v12, v13, v14, a8);
}


//==== nullsub_10 @ 0x20a508
void __fastcall nullsub_10(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44)
{
  ;
}


//==== nullsub_11 @ 0x20b388
void nullsub_11()
{
  ;
}


//==== sub_2126AB @ 0x2126ab
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_2126AB(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  unsigned int v12; // eax
  unsigned __int64 v13; // rbx
  __int64 v14; // rbp
  __int64 v15; // r13
  __int64 v16; // r14
  __int64 v18; // rdi
  __int64 v19; // rsi
  __int64 v20; // rcx
  bool v21; // of
  unsigned int v22; // eax
  __int64 v23; // rcx
  unsigned int v24; // eax
  __int64 v25; // r8
  __int64 v26; // rcx
  unsigned int v27; // eax
  bool v28; // cc
  __int64 v31; // rcx
  __int64 v32; // [rsp-20h] [rbp-20h]

  v18 = *(unsigned int *)(a3 + 55) + v16 + (*(_QWORD *)(a3 + 47) >> 24);
  *(_BYTE *)(v18 + a4) = a2;
  v19 = a2 >> 8;
  v20 = v12;
  v21 = __OFADD__(1, v12);
  v22 = v12 + 1;
  if ( v21 )
  {
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v15 - 40))(v18, v19, a3, v20);
    goto LABEL_14;
  }
  if ( (int)v20 >= v13 )
  {
LABEL_14:
    (*(void (__fastcall **)(__int64, __int64))(v15 - 40))(v18, v19);
    goto LABEL_15;
  }
  *(_BYTE *)(*(unsigned int *)(a3 + 55) + v16 + (*(_QWORD *)(a3 + 47) >> 24) + (int)v20) = v19;
  v18 = (unsigned int)v19 >> 8;
  v23 = v22;
  v21 = __OFADD__(1, v22);
  v24 = v22 + 1;
  if ( v21 )
  {
LABEL_15:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v15 - 40))(v18, v19, a3, v23);
    goto LABEL_16;
  }
  if ( (int)v23 >= v13 )
  {
LABEL_16:
    (*(void (__fastcall **)(__int64))(v15 - 40))(v18);
    goto LABEL_17;
  }
  v25 = *(unsigned int *)(a3 + 55) + v16 + (*(_QWORD *)(a3 + 47) >> 24);
  *(_BYTE *)(v25 + (int)v23) = BYTE1(v19);
  v19 = WORD1(v19);
  v26 = v24;
  v21 = __OFADD__(1, v24);
  v27 = v24 + 1;
  if ( v21 )
  {
LABEL_17:
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v15 - 40))(v18, v19, a3, v26);
    goto LABEL_18;
  }
  if ( (int)v26 >= v13 )
  {
LABEL_18:
    (*(void (__fastcall **)(__int64, __int64))(v15 - 40))(v18, v19);
    (*(void (**)(void))(v15 - 32))();
    (*(void (**)(void))(v15 - 32))();
    JUMPOUT(0x212865);
  }
  *(_BYTE *)(*(unsigned int *)(a3 + 55) + v16 + (*(_QWORD *)(a3 + 47) >> 24) + (int)v26) = BYTE1(v18);
  v28 = MEMORY[0x31001108C80] < 115;
  MEMORY[0x31001108C80] -= 115;
  if ( v28 )
  {
    v19 = 0x3100106770DLL;
    v32 = *(_QWORD *)(v14 - 16);
    MEMORY[0xFFFFFFFFA00ABBC0](v18, 0x3100106770DLL);
    v27 = v32;
  }
  if ( !__OFADD__(v27, v27) )
    return 2 * v27;
  __asm { vcvtsi2sd xmm15, xmm15, eax }
  v31 = *(_QWORD *)(v15 + 80);
  if ( (unsigned __int64)(v31 + 12) >= *(_QWORD *)(v15 + 88) )
    return ((__int64 (__stdcall *)(__int64, __int64, __int64, __int64, __int64, __int64))sub_212808)(
             v31,
             a3,
             v25,
             a6,
             a11,
             a12);
  *(_QWORD *)(v15 + 80) = v31 + 12;
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))sub_2127F3)(
           v18,
           v19,
           a3,
           v31 + 1,
           v25,
           a6,
           a7,
           a8,
           a9,
           a10);
}


//==== sub_212794 @ 0x212794
__int64 __fastcall sub_212794(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // r8
  __int64 v16; // r9
  __int64 v18; // [rsp+0h] [rbp-8h]

  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  MEMORY[0xFFFFFFFFA00ADB80]();
  return sub_2126AB(a1, v18, v13, v14, v15, v16, a7, a8, a9, a10, a11, a12);
}


//==== sub_2127F3 @ 0x2127f3
void __fastcall sub_2127F3(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 _RCX,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  *(_DWORD *)(_RCX - 1) = 1301;
  __asm { vmovsd  qword ptr [rcx+3], xmm15 }
  JUMPOUT(0x212773);
}


//==== sub_212808 @ 0x212808
void __fastcall sub_212808(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 _RCX; // rax
  __int64 v15; // rdx
  __int64 v16; // r8
  __int64 v17; // r9

  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  _RCX = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+8+var_8] }
  sub_2127F3(a1, a2, v15, _RCX, v16, v17, a7, a8, a9, a10, a11, a12);
}


//==== sub_2128B0 @ 0x2128b0
__int64 __fastcall sub_2128B0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48)
{
  return MEMORY[0x910150C66100000A];
}


//==== sub_217970 @ 0x217970
__int64 __fastcall sub_217970(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43)
{
  return MEMORY[0xF90128C30900000A];
}


//==== sub_219EB0 @ 0x219eb0
__int64 __fastcall sub_219EB0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43)
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)(
           a4,
           a3,
           a5,
           a6,
           a11,
           a12,
           a13,
           a14,
           a15,
           a16,
           a17,
           a18,
           a19,
           a20,
           a21,
           a22,
           a23,
           a24,
           a25,
           a26,
           a27,
           a28,
           a29,
           a30,
           a31,
           a32,
           a33,
           a34,
           a35,
           a36,
           a37,
           a38,
           a39,
           a40,
           a41,
           a42,
           a43);
}


//==== sub_21A8B0 @ 0x21a8b0
void sub_21A8B0()
{
  __asm { iret }
}


//==== sub_21A930 @ 0x21a930
void sub_21A930()
{
  __asm { iret }
}


//==== sub_22D2FC @ 0x22d2fc
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_22D2FC(
        double a1,
        __m128 _XMM1,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  char v9; // zf
  char v10; // pf
  __int64 v11; // r13
  bool v16; // of
  __int64 result; // rax
  __int64 v18; // rax

  __asm
  {
    vcvttpd2dq xmm15, xmm1
    vcvtdq2pd xmm15, xmm15
    vucomisd xmm15, xmm1
  }
  if ( v10 )
    goto LABEL_7;
  if ( !v9 )
    goto LABEL_7;
  __asm { vcvttsd2si eax, xmm1 }
  if ( !_EAX )
  {
    __asm { vpextrd r10d, xmm1, 1 }
    if ( _R10D < 0 )
      goto LABEL_7;
  }
  v16 = __OFADD__(_EAX, _EAX);
  result = (unsigned int)(2 * _EAX);
  if ( v16 )
  {
LABEL_7:
    v18 = *(_QWORD *)(v11 + 80);
    if ( (unsigned __int64)(v18 + 12) >= *(_QWORD *)(v11 + 88) )
    {
      return ((__int64 (__stdcall *)(__int64))sub_22D3BC)(a6);
    }
    else
    {
      *(_QWORD *)(v11 + 80) = v18 + 12;
      result = v18 + 1;
      *(_DWORD *)(result - 1) = 1301;
      __asm { vmovsd  qword ptr [rax+3], xmm1 }
    }
  }
  return result;
}


//==== sub_22D383 @ 0x22d383
__int64 __fastcall sub_22D383(
        __int64 a1,
        double a2,
        __m128 _XMM1,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v9; // rbp
  double v10; // xmm0_8
  __m128 _XMM1; // xmm1
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // r8
  __int64 v15; // r9
  __int64 v17; // [rsp+0h] [rbp-10h]

  __asm { vmovsd  [rsp+8+var_8], xmm1 }
  v17 = *(_QWORD *)(v9 - 16);
  v10 = MEMORY[0xFFFFFFFFA00ABBC0](a1, 0x3100106770DLL);
  __asm { vmovsd  xmm1, [rsp+10h+var_10] }
  return sub_22D2FC(v10, _XMM1, a1, 0x3100106770DLL, v12, v13, v14, v15, a9);
}


//==== sub_22D3BC @ 0x22d3bc
void __fastcall sub_22D3BC(
        __int64 a1,
        __int64 a2,
        double a3,
        __m128 _XMM1,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __asm { vmovsd  [rsp+8+var_8], xmm1 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm1, [rsp+8+var_8] }
  JUMPOUT(0x22D356);
}


//==== sub_2315A1 @ 0x2315a1
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_2315A1(
        __m128 _XMM0,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // zf
  char v9; // pf
  __int64 v10; // r13
  bool v15; // of
  __int64 result; // rax
  __int64 v17; // rax

  __asm
  {
    vcvttpd2dq xmm15, xmm0
    vcvtdq2pd xmm15, xmm15
    vucomisd xmm15, xmm0
  }
  if ( v9 )
    goto LABEL_7;
  if ( !v8 )
    goto LABEL_7;
  __asm { vcvttsd2si eax, xmm0 }
  if ( !_EAX )
  {
    __asm { vpextrd r10d, xmm0, 1 }
    if ( _R10D < 0 )
      goto LABEL_7;
  }
  v15 = __OFADD__(_EAX, _EAX);
  result = (unsigned int)(2 * _EAX);
  if ( v15 )
  {
LABEL_7:
    v17 = *(_QWORD *)(v10 + 80);
    if ( (unsigned __int64)(v17 + 12) >= *(_QWORD *)(v10 + 88) )
    {
      return ((__int64 (__stdcall *)(__int64))sub_2316D8)(a5);
    }
    else
    {
      *(_QWORD *)(v10 + 80) = v17 + 12;
      result = v17 + 1;
      *(_DWORD *)(result - 1) = 1301;
      __asm { vmovsd  qword ptr [rax+3], xmm0 }
    }
  }
  return result;
}


//==== sub_2316A2 @ 0x2316a2
__int64 __fastcall sub_2316A2(
        __int64 a1,
        __m128 _XMM0,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // rbp
  __m128 _XMM0; // xmm0
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // r8
  __int64 v13; // r9
  __int64 v15; // [rsp+0h] [rbp-10h]

  __asm { vmovsd  [rsp+8+var_8], xmm0 }
  v15 = *(_QWORD *)(v8 - 16);
  MEMORY[0xFFFFFFFFA00ABBC0](a1, 0x3100106770DLL);
  __asm { vmovsd  xmm0, [rsp+10h+var_10] }
  return sub_2315A1(_XMM0, a1, 0x3100106770DLL, v10, v11, v12, v13, a8);
}


//==== sub_2316D8 @ 0x2316d8
void __fastcall sub_2316D8(
        __int64 a1,
        __int64 a2,
        __m128 _XMM0,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __asm { vmovsd  [rsp+8+var_8], xmm0 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm0, [rsp+8+var_8] }
  JUMPOUT(0x2315FB);
}


//==== sub_28871B @ 0x28871b
__int64 __fastcall sub_28871B(
        __m128 _XMM0,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v11; // rbp
  _QWORD *v12; // r13
  __int64 v13; // r14
  __int64 v15; // rdi
  __int64 n0x71; // rax
  __int64 v17; // r8
  __int64 v18; // r9
  int n1341; // r10d
  __int64 v20; // rcx
  __int64 v21; // r8
  __int64 v22; // r9
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // r8
  __int64 v27; // r9
  __int64 v28; // rax
  void (__fastcall *v29)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, _QWORD, __int64); // rcx
  __int64 v30; // rbx
  __int64 v31; // r8
  __int64 v32; // r9
  __int64 v33; // rax
  __int64 v34; // rcx
  __int64 p_sub_227AC9; // rax
  __int64 v36; // r8
  __int64 v37; // r9
  __int64 v38; // rax
  __int64 (__fastcall *v39)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v40; // rax
  __int64 v41; // r8
  __int64 v42; // r9
  __int64 v43; // rcx
  __int64 v44; // rdx
  __int64 v45; // rax
  __int64 v46; // r8
  __int64 v47; // r9
  __int64 v48; // rcx
  __int64 n0x71_1; // rax
  int n1341_1; // r10d
  __int64 v51; // rdx
  int v52; // edx
  bool v53; // of
  void (__fastcall *v54)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64); // rcx
  bool v55; // cc
  __int64 v58; // rdx
  __int64 v60; // [rsp-130h] [rbp-130h]

  *(_DWORD *)(_RAX - 1) = 1301;
  __asm { vmovsd  qword ptr [rax+3], xmm0 }
  *(_QWORD *)(v11 - 56) = _RAX;
  v15 = 0x31001097065LL;
  n0x71 = MEMORY[0xFFFFFFFFA003E800](0x31001097065LL, 0x3100106770DLL);
  if ( (n0x71 & 1) != 0 )
  {
    if ( (unsigned int)n0x71 < 0x71 )
      goto LABEL_18;
    if ( (_DWORD)n0x71 == 113 )
    {
LABEL_6:
      v20 = v13 + MEMORY[0x31002034C64];
      *(_QWORD *)(v11 - 64) = v20;
      if ( (_DWORD)v20 == (_DWORD)&unk_2FFFD )
      {
        MEMORY[0xFFFFFFFFA00ABBC0](0x31001097065LL, 0x3100106770DLL);
        JUMPOUT(0x288FCA);
      }
      *(_QWORD *)(v11 - 80) = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v12[84] + 316880LL))(
                                0x310019C98F9LL,
                                0x310019C96D5LL,
                                v13 + 17,
                                *(_QWORD *)(v12[84] + 316880LL),
                                v17,
                                v18,
                                0x310010676ADLL,
                                6030,
                                27960,
                                21036,
                                16882);
      v23 = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v12[84] + 316896LL))(
              0x310019C9919LL,
              0x310019C96D5LL,
              v13 + 17,
              *(_QWORD *)(v12[84] + 316896LL),
              v21,
              v22,
              0x310010676ADLL,
              5480,
              4290,
              4294964314LL,
              16344);
      *(_QWORD *)(v11 - 72) = v23;
      v24 = *(_QWORD *)(v11 - 80);
      if ( (v24 & 1) != 0 && *(_DWORD *)(v24 - 1) <= 0x425u )
      {
        if ( (v23 & 1) != 0 && *(_DWORD *)(v23 - 1) <= 0x425u )
        {
          v25 = MEMORY[0xFFFFFFFFA00AC040](0x310019C9919LL, 0x3100106770DLL);
          if ( (_DWORD)v25 == (_DWORD)&unk_228359
            || (v25 & 1) != 0
            && *(_DWORD *)(v25 - 1) <= 0x425u
            && *(_DWORD *)(v25 + 7) == 12
            && (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() == 113 )
          {
            v28 = *(_QWORD *)(v11 - 64);
            if ( (v28 & 1) != 0 && *(_DWORD *)(v28 - 1) == 17227005 )
            {
              v15 = 0x31001107D95LL;
              v29 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, _QWORD, __int64))(v12[84] + 16 * ((unsigned int)&unk_1AE500 >> 8));
              v29(0x31001107D95LL, 0x31001108431LL, v13 + 17, v29, v26, v27, v28, *(_QWORD *)(v11 - 56), 310411440);
              goto LABEL_18;
            }
LABEL_81:
            ((void (*)(void))*(v12 - 5))();
LABEL_82:
            ((void (*)(void))*(v12 - 5))();
LABEL_83:
            ((void (*)(void))*(v12 - 5))();
LABEL_84:
            ((void (*)(void))*(v12 - 5))();
LABEL_85:
            ((void (*)(void))*(v12 - 5))();
            goto LABEL_86;
          }
LABEL_80:
          ((void (*)(void))*(v12 - 5))();
          goto LABEL_81;
        }
      }
      else
      {
        ((void (*)(void))*(v12 - 5))();
      }
      ((void (*)(void))*(v12 - 5))();
      goto LABEL_80;
    }
    n1341 = v13 + *(_DWORD *)(n0x71 - 1);
    if ( n1341 == 1301 )
    {
      __asm
      {
        vxorpd  xmm15, xmm15, xmm15
        vucomisd xmm15, qword ptr [rax+3]
      }
    }
    else if ( n1341 != 1341 || (*(_DWORD *)(n0x71 + 3) & 0xFFFFFF00) != 0 )
    {
      goto LABEL_6;
    }
  }
  else if ( (_DWORD)n0x71 )
  {
    goto LABEL_6;
  }
LABEL_18:
  if ( (*(_DWORD *)(v11 - 88) & 1) == 0 )
  {
    if ( (_DWORD)v13 + MEMORY[0x310019C9838] == (_DWORD)&unk_2FFFD )
    {
      MEMORY[0xFFFFFFFFA00ABBC0](v15, 0x3100106770DLL);
      JUMPOUT(0x28901D);
    }
    MEMORY[0x310019C9838] = v13 + 85;
  }
  v30 = v13 + MEMORY[0x31002034C64];
  *(_QWORD *)(v11 - 56) = v30;
  if ( (_DWORD)v30 == (_DWORD)&unk_2FFFD )
  {
    MEMORY[0xFFFFFFFFA00ABBC0](v15, 0x3100106770DLL);
    JUMPOUT(0x289046);
  }
  *(_QWORD *)(v11 - 64) = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v12[84] + 316880LL))(
                            0x310019C98F9LL,
                            0x310019C96D5LL,
                            v13 + 17,
                            *(_QWORD *)(v12[84] + 316880LL),
                            v17,
                            v18,
                            0x310010676ADLL,
                            4294966756LL,
                            4294960650LL,
                            4766,
                            612);
  v33 = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v12[84] + 316880LL))(
          0x310019C98F9LL,
          0x310019C96D5LL,
          v13 + 17,
          *(_QWORD *)(v12[84] + 316880LL),
          v31,
          v32,
          0x310010676ADLL,
          10714,
          26464,
          18732,
          14578);
  *(_QWORD *)(v11 - 72) = v33;
  v34 = *(_QWORD *)(v11 - 64);
  if ( (v34 & 1) == 0 || *(_DWORD *)(v34 - 1) > 0x425u )
    goto LABEL_82;
  if ( (v33 & 1) == 0 || *(_DWORD *)(v33 - 1) > 0x425u )
    goto LABEL_83;
  p_sub_227AC9 = MEMORY[0xFFFFFFFFA00AC040](0x310019C98F9LL, 0x3100106770DLL);
  if ( (_DWORD)p_sub_227AC9 != (_DWORD)sub_227AC9
    && ((p_sub_227AC9 & 1) == 0
     || *(_DWORD *)(p_sub_227AC9 - 1) > 0x425u
     || *(_DWORD *)(p_sub_227AC9 + 7) != 12
     || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
  {
    goto LABEL_84;
  }
  v38 = *(_QWORD *)(v11 - 56);
  if ( (v38 & 1) == 0 || *(_DWORD *)(v38 - 1) != 17227005 )
    goto LABEL_85;
  v39 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64))(v12[84] + 16 * ((unsigned int)&unk_1B0B00 >> 8));
  v40 = v39(0x31001108835LL, 0x31001108431LL, v13 + 17, v39, v36, v37, v13 + 17, v38, 345146976);
  *(_QWORD *)(v11 - 72) = v40;
  if ( (v40 & 1) != 0 )
  {
LABEL_86:
    ((void (*)(void))*(v12 - 5))();
LABEL_87:
    ((void (*)(void))*(v12 - 5))();
    goto LABEL_88;
  }
  if ( (((int)v40 >> 1) & 1) != 0 )
  {
    v43 = v13 + 113;
  }
  else
  {
    v43 = v13 + MEMORY[0x310019C9838];
    *(_QWORD *)(v11 - 72) = v43;
    if ( (_DWORD)v43 == (_DWORD)&unk_2FFFD )
    {
      MEMORY[0xFFFFFFFFA00ABBC0](0x31001108835LL, 0x3100106770DLL);
      JUMPOUT(0x289099);
    }
  }
  *(_QWORD *)(v11 - 72) = v43;
  *(_QWORD *)(v11 - 56) = v13 + MEMORY[0x31002034C64];
  (*(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v12[84] + 316880LL))(
    0x310019C98F9LL,
    0x310019C96D5LL,
    v13 + 17,
    *(_QWORD *)(v12[84] + 316880LL),
    v41,
    v42,
    0x310010676ADLL,
    15400,
    484,
    16116,
    11962);
  v45 = MEMORY[0xFFFFFFFFA00622C0](0x310019C98F9LL, 0x310019C96D5LL, v44, 130);
  if ( (_DWORD)v45 != (_DWORD)&unk_227ED5
    && ((v45 & 1) == 0
     || *(_DWORD *)(v45 - 1) > 0x425u
     || *(_DWORD *)(v45 + 7) != 13
     || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
  {
    goto LABEL_87;
  }
  v48 = *(_QWORD *)(v11 - 56);
  if ( (v48 & 1) == 0 || *(_DWORD *)(v48 - 1) != 17227005 )
  {
LABEL_88:
    ((void (*)(void))*(v12 - 5))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    ((void (*)(void))*(v12 - 4))();
    _RAX = ((__int64 (*)(void))*(v12 - 4))();
    __asm { sldt    word ptr [rax] }
    MEMORY[0xFFFFFFFFA3289231] += BYTE1(_RAX);
    JUMPOUT(0x289231);
  }
  n0x71_1 = *(_QWORD *)(v11 - 72);
  if ( (n0x71_1 & 1) == 0 )
  {
    if ( !(_DWORD)n0x71_1 )
      goto LABEL_49;
LABEL_48:
    v51 = 0;
    goto LABEL_50;
  }
  if ( (unsigned int)n0x71_1 < 0x71 )
    goto LABEL_49;
  if ( (_DWORD)n0x71_1 == 113 )
    goto LABEL_48;
  n1341_1 = v13 + *(_DWORD *)(n0x71_1 - 1);
  if ( n1341_1 == 1301 )
  {
    __asm
    {
      vxorpd  xmm15, xmm15, xmm15
      vucomisd xmm15, qword ptr [rax+3]
    }
  }
  else if ( n1341_1 != 1341 || (*(_DWORD *)(n0x71_1 + 3) & 0xFFFFFF00) != 0 )
  {
    goto LABEL_48;
  }
LABEL_49:
  v52 = *(_QWORD *)(v11 - 88);
  v53 = __OFADD__(v52, v52);
  v51 = (unsigned int)(2 * v52);
  if ( v53 )
  {
    __asm { vcvtsi2sd xmm15, xmm15, eax }
    v58 = v12[10];
    if ( (unsigned __int64)(v58 + 12) >= v12[11] )
      return sub_289155(v48, v58, v46);
    v12[10] = v58 + 12;
    return sub_28911C(0x310019C98F9LL, 0x310019C96D5LL, v58 + 1, v48, v46, v47);
  }
LABEL_50:
  *(_QWORD *)(v11 - 72) = v51;
  v60 = v48;
  v54 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64))(v12[84] + 16 * ((unsigned int)qword_1B2100 >> 8));
  v54(0x31001108C55LL, 0x31001108431LL, v13 + 17, v54, v46, v47, v13 + 17, v60, v51, 310411448, 0, 0x3100101F69DLL);
  v55 = MEMORY[0x31001F628D0] < 470;
  MEMORY[0x31001F628D0] -= 470;
  if ( v55 )
    MEMORY[0xFFFFFFFFA00ABBC0](0x31001108C55LL, 0x3100106770DLL);
  return v13 + 17;
}


//==== sub_288F4A @ 0x288f4a
__int64 __fastcall sub_288F4A(
        __int64 a1,
        __int64 a2,
        __m128 _XMM0,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __m128 _XMM0; // xmm0
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9

  __asm { vmovsd  [rsp+8+var_8], xmm0 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm0, [rsp+8+var_8] }
  return sub_28871B(_XMM0, a1, a2, v11, v12, v13, v14, a8, a9, a10);
}


//==== sub_28911C @ 0x28911c
void __fastcall sub_28911C(
        __int64 a1,
        __int64 a2,
        __int64 _RDX,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  *(_DWORD *)(_RDX - 1) = 1301;
  __asm { vmovsd  qword ptr [rdx+3], xmm15 }
  JUMPOUT(0x288CCE);
}


//==== sub_289155 @ 0x289155
void __fastcall sub_289155(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 _RDX; // rax
  __int64 v12; // r8
  __int64 v13; // r9

  __asm { vmovsd  [rsp+10h+var_10], xmm15 }
  _RDX = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+10h+var_10] }
  sub_28911C(a1, a2, _RDX, a4, v12, v13, a7, a8, a9);
}


//==== sub_2CB84E @ 0x2cb84e
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_2CB84E(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  unsigned int n0x3FFFFFFF; // eax
  __int64 v10; // rbp
  _QWORD *v11; // r13
  __int64 v12; // r14
  void (__fastcall *v14)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, __int64); // rcx
  bool v15; // cc
  unsigned __int64 v18; // r10

  *(_QWORD *)(v10 - 56) = n0x3FFFFFFF;
  if ( n0x3FFFFFFF > 0x3FFFFFFF )
  {
    __asm { vcvtsi2sd xmm15, xmm15, r10 }
    v18 = v11[10] + 12LL;
    if ( v18 >= v11[11] )
    {
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64, __int64))sub_2CBA80)(
               a1,
               a2,
               n0x3FFFFFFF,
               a4,
               a5,
               a6);
    }
    else
    {
      v11[10] = v18;
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64, __int64))sub_2CBA47)(
               a1,
               a2,
               n0x3FFFFFFF,
               a4,
               a5,
               a6);
    }
  }
  else
  {
    v14 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, _QWORD, __int64, _QWORD, __int64))(v11[84] + 16 * ((unsigned int)qword_1B2100 >> 8));
    v14(
      0x31001108C55LL,
      0x31001108431LL,
      v12 + 17,
      v14,
      a5,
      a6,
      v12 + 17,
      a4,
      2 * n0x3FFFFFFF,
      310411480,
      0,
      0x3100101F69DLL);
    v15 = MEMORY[0x31001F62990] < 149;
    MEMORY[0x31001F62990] -= 149;
    if ( v15 )
      MEMORY[0xFFFFFFFFA00ABBC0](0x31001108C55LL, 0x3100106770DLL);
    return v12 + 17;
  }
}


//==== sub_2CBA0A @ 0x2cba0a
__int64 __fastcall sub_2CBA0A(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // r8
  __int64 v13; // r9

  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  MEMORY[0xFFFFFFFFA00ADB80](a1);
  return sub_2CB84E(a1, a2, v10, v11, v12, v13, a7, a8, a9);
}


//==== sub_2CBA47 @ 0x2cba47
void __fastcall sub_2CBA47(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  *(_DWORD *)(_RAX - 1) = 1301;
  __asm { vmovsd  qword ptr [rax+3], xmm15 }
  JUMPOUT(0x2CB863);
}


//==== sub_2CBA80 @ 0x2cba80
void __fastcall sub_2CBA80(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v11; // r8
  __int64 v12; // r9
  __int64 v15; // [rsp+10h] [rbp-8h]

  __asm { vmovsd  [rsp+18h+var_18], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+18h+var_18] }
  sub_2CBA47(a1, a2, a3, v15, v11, v12, a7, a8, a9);
}


//==== sub_331130 @ 0x331130
__int64 sub_331130()
{
  return MEMORY[0xB50149D6C500000A];
}


//==== sub_351530 @ 0x351530
void sub_351530()
{
  __asm { iret }
}


//==== sub_383930 @ 0x383930
__int64 sub_383930()
{
  _BYTE retaddr[16]; // [rsp+0h] [rbp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_QWORD *)retaddr)();
}


//==== nullsub_12 @ 0x3cbd29
void nullsub_12()
{
  ;
}


//==== sub_3CBE3A @ 0x3cbe3a
void __fastcall sub_3CBE3A(__int64 _RDI)
{
  *(_DWORD *)(_RDI - 1) = 1301;
  __asm { vmovsd  qword ptr [rdi+3], xmm15 }
  JUMPOUT(0x3CAF99);
}


//==== sub_3CBE6E @ 0x3cbe6e
void __fastcall sub_3CBE6E(__int64 a1, __int64 _RSI)
{
  *(_DWORD *)(_RSI - 1) = 1301;
  __asm { vmovsd  qword ptr [rsi+3], xmm15 }
  JUMPOUT(0x3CAFA4);
}


//==== sub_3CBECB @ 0x3cbecb
void __fastcall sub_3CBECB(__int64 a1, __int64 _RSI)
{
  *(_DWORD *)(_RSI - 1) = 1301;
  __asm { vmovsd  qword ptr [rsi+3], xmm15 }
  JUMPOUT(0x3CB140);
}


//==== sub_3CBF3B @ 0x3cbf3b
void __fastcall sub_3CBF3B(__int64 _RDI)
{
  *(_DWORD *)(_RDI - 1) = 1301;
  __asm { vmovsd  qword ptr [rdi+3], xmm15 }
  JUMPOUT(0x3CB2C0);
}


//==== sub_3CBFC4 @ 0x3cbfc4
void __fastcall sub_3CBFC4()
{
  *(_DWORD *)(_RBX - 1) = 1301;
  __asm { vmovsd  qword ptr [rbx+3], xmm15 }
  JUMPOUT(0x3CB4F3);
}


//==== sub_3CBFF7 @ 0x3cbff7
// bad sp value at call has been detected, the output may be wrong!
void __fastcall sub_3CBFF7(
        __int64 a1,
        __int64 a2,
        __int64 _RDX,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // rdi
  __int64 v9; // rsi
  __int64 v10; // rax
  __int64 v11; // r8
  __int64 v12; // r9
  __int64 n113; // rcx
  int n1301; // r10d
  __int64 (__fastcall *v15)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 (__fastcall *v16)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v17; // r8
  __int64 v18; // r9
  __int64 v19; // rax
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rax
  __int64 n0x71; // rax
  __int64 v24; // rdx
  __int64 v25; // rcx
  __int64 v26; // r8
  __int64 v27; // r9
  int n1301_1; // r10d
  __int64 n113_1; // rax
  int n1341; // r10d
  __int64 v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // rbx
  int v34; // r8d
  __int64 v35; // r8
  __int64 v36; // rdi
  __int64 v37; // rsi
  __int64 v38; // r8
  __int64 v39; // r9
  __int64 (__fastcall *v40)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v41; // rax
  __int64 v42; // rcx
  __int64 v43; // r8
  __int64 (__fastcall *v44)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v45; // r9
  __int64 v46; // rax
  __int64 n23425149; // rax
  __int64 v48; // r8
  __int64 v49; // rcx
  int v50; // edx
  __int64 v51; // rdx
  __int64 (__fastcall *v52)(__int64, __int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64, __int64, __int64); // rcx
  __int64 v53; // rax
  __int64 n23425149_1; // rax
  __int64 v55; // r8
  __int64 v56; // r9
  __int64 v57; // rdi
  __int64 v58; // rax
  int v59; // eax
  bool v60; // of
  unsigned int v61; // eax
  __int64 v62; // rcx
  __int64 v63; // rdx
  __int64 v64; // rbx
  __int64 v65; // r9
  __int64 (__fastcall *v66)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64, _QWORD); // rcx
  __int64 v67; // rcx
  __int64 v68; // rdi
  __int64 v69; // r8
  __int64 (__fastcall *v70)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v71; // r9
  __int64 v72; // rax
  __int64 v73; // rcx
  __int64 n18536041; // rax
  __int64 v75; // rcx
  __int64 v76; // rdi
  __int64 v77; // r8
  __int64 (__fastcall *v78)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v79; // r9
  __int64 v80; // rax
  __int64 v81; // rcx
  int v82; // edx
  __int64 v83; // rdx
  int v84; // esi
  int v85; // esi
  __int64 (__fastcall *v86)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v87; // rcx
  __int64 v88; // rbx
  __int64 v89; // rdi
  __int64 v90; // r8
  __int64 v91; // r9
  __int64 (__fastcall *v92)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v93; // rax
  __int64 v94; // rdx
  __int64 v95; // r8
  __int64 v96; // r9
  __int64 v97; // rcx
  __int64 n28205697; // rax
  __int64 v99; // r8
  __int64 v100; // r9
  void (__fastcall *v101)(__int64, __int64, __int64, _QWORD, __int64, __int64, _QWORD, __int64, _QWORD); // rcx
  int v102; // ebx
  __int64 v103; // rbx
  bool v104; // cc
  __int64 (__fastcall *v105)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v106; // rdi
  __int64 (__fastcall *v107)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v108; // r8
  __int64 v109; // r9
  __int64 v110; // rax
  __int64 v111; // rcx
  __int64 v112; // rcx
  __int64 v113; // rdi
  __int64 v114; // r8
  __int64 (__fastcall *v115)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v116; // r9
  __int64 v117; // rax
  __int64 v118; // rcx
  __int64 v119; // rdi
  __int64 v120; // r8
  __int64 (__fastcall *v121)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v122; // r9
  __int64 v123; // rax
  __int64 v124; // rdi
  __int64 (__fastcall *v125)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v126; // r8
  __int64 v127; // r9
  __int64 v128; // rax
  __int64 v129; // rcx
  __int64 (__fastcall *v130)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v131; // r8
  __int64 v132; // r9
  __int64 n22129; // rax
  __int64 v134; // rcx
  __int64 v135; // rdi
  __int64 v136; // r8
  __int64 v137; // r9
  __int64 (__fastcall *v138)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // rcx
  __int64 v139; // rax
  __int64 v140; // rcx
  __int64 v142; // rdi
  __int64 v144; // rsi
  __int64 v146; // rsi
  __int64 v148; // rdi
  unsigned __int64 v150; // r10
  __int64 v151; // rdx
  __int64 v152; // rbx
  __int64 v153; // rbp
  _QWORD *v154; // r13
  __int64 v155; // r14
  unsigned __int64 v158; // r10
  __int64 v159; // [rsp-198h] [rbp-198h]
  __int64 v160; // [rsp-180h] [rbp-180h]
  __int64 v161; // [rsp-170h] [rbp-170h]
  __int64 v162; // [rsp-168h] [rbp-168h]
  __int64 v163; // [rsp-100h] [rbp-100h]
  __int64 v164; // [rsp-F8h] [rbp-F8h]
  __int64 v165; // [rsp-E8h] [rbp-E8h]
  __int64 v166; // [rsp-D8h] [rbp-D8h]
  __int64 v167; // [rsp-D0h] [rbp-D0h]
  __int64 v168; // [rsp-A0h] [rbp-A0h]
  __int64 v169; // [rsp-98h] [rbp-98h]
  __int64 v170; // [rsp-90h] [rbp-90h]
  __int64 v171; // [rsp-88h] [rbp-88h]
  __int64 v172; // [rsp-80h] [rbp-80h]
  __int64 v173; // [rsp-78h] [rbp-78h]
  __int64 v174; // [rsp-70h] [rbp-70h]
  __int64 v175; // [rsp-68h] [rbp-68h]
  __int64 v176; // [rsp-60h] [rbp-60h]
  __int64 v177; // [rsp-58h] [rbp-58h]

LABEL_1:
  *(_DWORD *)(_RDX - 1) = 1301;
  __asm { vmovsd  qword ptr [rdx+3], xmm15 }
LABEL_84:
  v86 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  *(_QWORD *)(v153 - 112) = v86(
                              *(_QWORD *)(v153 - 56),
                              *(_QWORD *)(v153 - 32),
                              v155 + 17,
                              v86,
                              _RDX,
                              a6,
                              0x310010676ADLL,
                              11368,
                              v152,
                              _RDX,
                              4294957022LL);
  v87 = *(_QWORD *)(v153 - 48);
  v88 = v155 + *(unsigned int *)(v87 + 99);
  v89 = *(_QWORD *)(v153 - 40);
  v90 = v155 + *(unsigned int *)(v87 + 103);
  v91 = v155 + *(unsigned int *)(v87 + 95);
  v92 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
  v93 = v92(v89, *(_QWORD *)(v153 - 32), v155 + 17, v92, v90, v91, 0x310010676ADLL, v91, v88, v90, 4294965744LL);
  *(_QWORD *)(v153 - 120) = v93;
  v97 = *(_QWORD *)(v153 - 112);
  if ( (v97 & 1) == 0 || *(_DWORD *)(v97 - 1) > 0x425u )
    goto LABEL_195;
  if ( (v93 & 1) == 0 || *(_DWORD *)(v93 - 1) > 0x425u )
    goto LABEL_196;
  n28205697 = MEMORY[0xFFFFFFFFA00AC040](v89, 0x3100106770DLL);
  if ( (_DWORD)n28205697 != 28205697
    && ((n28205697 & 1) == 0
     || *(_DWORD *)(n28205697 - 1) > 0x425u
     || *(_DWORD *)(n28205697 + 7) != 11
     || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
  {
    goto LABEL_197;
  }
  if ( (unsigned int)*(_QWORD *)(v153 - 88) != 19270093 )
    goto LABEL_198;
  v8 = 0x310012609CDLL;
  v101 = *(void (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, _QWORD, __int64, _QWORD))(v154[84] + 16 * ((unsigned int)&unk_26B800 >> 8));
  v101(
    0x310012609CDLL,
    0x3100155D799LL,
    v155 + 17,
    v101,
    v99,
    v100,
    *(_QWORD *)(v153 - 104),
    0x31001ED8925LL,
    *(_QWORD *)(v153 + 24));
  v102 = *(_QWORD *)(v153 - 128);
  v60 = __OFADD__(v102, v102);
  v103 = (unsigned int)(2 * v102);
  if ( v60 )
  {
    __asm { vcvtsi2sd xmm15, xmm15, eax }
    v158 = v154[10] + 12LL;
    if ( v158 >= v154[11] )
    {
      sub_3CC223(v25, v24);
    }
    else
    {
      v154[10] = v158;
      sub_3CC054(v25, v24);
    }
    return;
  }
  while ( 1 )
  {
    *(_QWORD *)(v153 - 96) = v103;
    v104 = MEMORY[0x31001B1CE84] < 591;
    MEMORY[0x31001B1CE84] -= 591;
    if ( v104 )
    {
      MEMORY[0xFFFFFFFFA00ABBC0](v8, 0x3100106770DLL, v24, v25, v26, v27, *(_QWORD *)(v153 - 16), v103, 0x31001B1CE79LL);
      v103 = v172;
    }
    *(_QWORD *)(v153 - 80) = v103;
    v8 = 0x3100109048DLL;
    v9 = 0x3100106770DLL;
    v174 = *(_QWORD *)(v153 - 72);
    v10 = MEMORY[0xFFFFFFFFA008DD80](0x3100109048DLL, 0x3100106770DLL, v155 + 17);
    *(_QWORD *)(v153 - 88) = v10;
    if ( (v10 & 1) == 0 || *(_DWORD *)(v10 - 1) < (unsigned int)&unk_1A0000 )
    {
      MEMORY[0xFFFFFFFFA00ABBC0](0x3100109048DLL, *(_QWORD *)(v153 - 32));
      MEMORY[0xFFFFFFFFA00ABBC0](0x3100109048DLL);
      __debugbreak();
    }
    if ( (v10 & 1) == 0 || *(_DWORD *)(v10 - 1) != 17251549 )
    {
      ((void (*)(void))*(v154 - 5))();
LABEL_174:
      ((void (*)(void))*(v154 - 5))();
LABEL_175:
      ((void (*)(void))*(v154 - 5))();
LABEL_176:
      ((void (*)(void))*(v154 - 5))();
LABEL_177:
      ((void (*)(void))*(v154 - 5))();
LABEL_178:
      ((void (__fastcall *)(__int64, __int64, __int64))*(v154 - 5))(v8, v9, v32);
LABEL_179:
      ((void (__fastcall *)(__int64, __int64, __int64))*(v154 - 5))(v8, v9, v32);
LABEL_180:
      ((void (*)(void))*(v154 - 5))();
LABEL_181:
      ((void (*)(void))*(v154 - 5))();
LABEL_182:
      ((void (*)(void))*(v154 - 5))();
LABEL_183:
      ((void (*)(void))*(v154 - 5))();
LABEL_184:
      ((void (*)(void))*(v154 - 5))();
LABEL_185:
      ((void (*)(void))*(v154 - 5))();
LABEL_186:
      ((void (*)(void))*(v154 - 5))();
LABEL_187:
      ((void (*)(void))*(v154 - 5))();
LABEL_188:
      ((void (__fastcall *)(__int64, __int64, __int64))*(v154 - 5))(v8, v9, v63);
LABEL_189:
      ((void (*)(void))*(v154 - 5))();
LABEL_190:
      ((void (*)(void))*(v154 - 5))();
LABEL_191:
      ((void (*)(void))*(v154 - 5))();
LABEL_192:
      ((void (*)(void))*(v154 - 5))();
LABEL_193:
      ((void (*)(void))*(v154 - 5))();
LABEL_194:
      ((void (*)(void))*(v154 - 5))();
LABEL_195:
      ((void (*)(void))*(v154 - 5))();
LABEL_196:
      ((void (__stdcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))*(v154 - 5))(
        v97,
        v94,
        v95,
        v96,
        v168,
        v169,
        v170,
        v171,
        v172,
        v173,
        v174,
        v175,
        v176,
        v177);
LABEL_197:
      ((void (*)(void))*(v154 - 5))();
LABEL_198:
      ((void (*)(void))*(v154 - 5))();
LABEL_199:
      ((void (*)(void))*(v154 - 5))();
LABEL_200:
      ((void (*)(void))*(v154 - 5))();
LABEL_201:
      ((void (*)(void))*(v154 - 5))();
LABEL_202:
      ((void (*)(void))*(v154 - 5))();
LABEL_203:
      ((void (*)(void))*(v154 - 5))();
LABEL_204:
      ((void (*)(void))*(v154 - 5))();
LABEL_205:
      ((void (*)(void))*(v154 - 5))();
LABEL_206:
      ((void (*)(void))*(v154 - 5))();
LABEL_207:
      ((void (*)(void))*(v154 - 5))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      ((void (*)(void))*(v154 - 4))();
      JUMPOUT(0x3CC3AE);
    }
    n113 = v155 + *(unsigned int *)(v10 + 15);
    if ( (n113 & 1) == 0 )
    {
      if ( (_DWORD)n113 )
        break;
      goto LABEL_13;
    }
    if ( (unsigned int)n113 >= 0x71 )
    {
      if ( (_DWORD)n113 == 113 )
        break;
      n1301 = v155 + *(_DWORD *)(n113 - 1);
      if ( n1301 == 1301 )
      {
        __asm
        {
          vxorpd  xmm15, xmm15, xmm15
          vucomisd xmm15, qword ptr [rcx+3]
        }
        goto LABEL_13;
      }
      if ( n1301 != 1341 || (*(_DWORD *)(n113 + 3) & 0xFFFFFF00) != 0 )
        break;
    }
LABEL_13:
    *(_QWORD *)(v153 - 96) = v155 + *(unsigned int *)(v10 + 11);
    v15 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
    *(_QWORD *)(v153 - 88) = v15(
                               *(_QWORD *)(v153 - 40),
                               *(_QWORD *)(v153 - 32),
                               v155 + 17,
                               v15,
                               v11,
                               v12,
                               0x310010676ADLL,
                               23374,
                               22134,
                               v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 11LL),
                               21680);
    v8 = *(_QWORD *)(v153 - 40);
    v9 = *(_QWORD *)(v153 - 32);
    v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
    v19 = v16(
            v8,
            v9,
            v155 + 17,
            v16,
            v17,
            v18,
            0x310010676ADLL,
            20362,
            15236,
            v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 15LL),
            6708);
    *(_QWORD *)(v153 - 104) = v19;
    v20 = *(_QWORD *)(v153 - 88);
    if ( (v20 & 1) == 0 || *(_DWORD *)(v20 - 1) > 0x425u )
      goto LABEL_174;
    if ( (v19 & 1) == 0 || *(_DWORD *)(v19 - 1) > 0x425u )
      goto LABEL_175;
    v9 = 0x3100106770DLL;
    v21 = MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
    if ( (_DWORD)v21 != (_DWORD)byte_21B349
      && ((v21 & 1) == 0
       || *(_DWORD *)(v21 - 1) > 0x425u
       || *(_DWORD *)(v21 + 7) != 11
       || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
    {
      goto LABEL_176;
    }
    v22 = *(_QWORD *)(v153 - 96);
    if ( (v22 & 1) == 0 || *(_DWORD *)(v22 - 1) != 28334745 )
      goto LABEL_177;
    v9 = 0x3100106770DLL;
    n0x71 = MEMORY[0xFFFFFFFF9FFF77C0](v8, 0x3100106770DLL, 0x7FF628BC5DB0LL, 0);
    if ( (n0x71 & 1) != 0 )
    {
      if ( (unsigned int)n0x71 < 0x71 )
        goto LABEL_29;
      if ( (_DWORD)n0x71 == 113 )
        goto LABEL_95;
      n1301_1 = v155 + *(_DWORD *)(n0x71 - 1);
      if ( n1301_1 == 1301 )
      {
        __asm
        {
          vxorpd  xmm15, xmm15, xmm15
          vucomisd xmm15, qword ptr [rax+3]
        }
LABEL_29:
        n113_1 = *(_QWORD *)(v153 + 24);
        if ( (n113_1 & 1) != 0 )
        {
          if ( (unsigned int)n113_1 >= 0x71 )
          {
            if ( (_DWORD)n113_1 == 113 )
              goto LABEL_34;
            n1341 = v155 + *(_DWORD *)(n113_1 - 1);
            if ( n1341 == 1301 )
            {
              __asm
              {
                vxorpd  xmm15, xmm15, xmm15
                vucomisd xmm15, qword ptr [rax+3]
              }
            }
            else if ( n1341 != 1341 || (*(_DWORD *)(n113_1 + 3) & 0xFFFFFF00) != 0 )
            {
LABEL_34:
              v31 = *(_QWORD *)(v153 - 48);
              v32 = v155 + *(unsigned int *)(v31 + 19);
              v33 = v155 + *(unsigned int *)(v31 + 23);
              v8 = *(unsigned int *)(v31 + 27);
              v9 = (unsigned int)((int)v8 >> 1);
              if ( !(_DWORD)v9 )
                goto LABEL_178;
              v9 = (unsigned int)-(int)v9;
              if ( __OFSUB__((_DWORD)v9, 1) )
                goto LABEL_178;
              v34 = *(int *)(v31 + 31) >> 1;
              if ( !v34 )
                goto LABEL_179;
              v35 = (unsigned int)-v34;
              if ( __OFSUB__((_DWORD)v35, 1) )
                goto LABEL_179;
              v36 = (unsigned int)(2 * v9);
              if ( __OFADD__((_DWORD)v9, (_DWORD)v9) )
              {
                __asm { vcvtsi2sd xmm15, xmm15, esi }
                v142 = v154[10];
                if ( (unsigned __int64)(v142 + 12) >= v154[11] )
                {
                  sub_3CC115(v142, v9, v32, v31, v35);
                }
                else
                {
                  v154[10] = v142 + 12;
                  sub_3CBE3A(v142 + 1);
                }
                return;
              }
              v37 = (unsigned int)(2 * v35);
              if ( __OFADD__((_DWORD)v35, (_DWORD)v35) )
              {
                __asm { vcvtsi2sd xmm15, xmm15, r8d }
                v144 = v154[10];
                if ( (unsigned __int64)(v144 + 12) >= v154[11] )
                {
                  sub_3CC146(v36, v144, v32, v31, v35);
                }
                else
                {
                  v154[10] = v144 + 12;
                  sub_3CBE6E(v36, v144 + 1);
                }
                return;
              }
              v38 = v36;
              v8 = *(_QWORD *)(v153 - 40);
              v39 = v37;
              v9 = *(_QWORD *)(v153 - 32);
              v165 = v155 + *(unsigned int *)(v31 + 19);
              v40 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
              v41 = v40(v8, v9, v155 + 17, v40, v38, v39, 0x310010676ADLL, v165, v33, v38, v39);
              if ( (v41 & 1) == 0 || *(_DWORD *)(v41 - 1) > 0x425u )
                goto LABEL_180;
              *(_QWORD *)(v153 - 104) = MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
              v42 = *(_QWORD *)(v153 - 48);
              v8 = *(_QWORD *)(v153 - 56);
              v9 = *(_QWORD *)(v153 - 32);
              v43 = v155 + *(unsigned int *)(v42 + 35);
              v164 = v155 + *(unsigned int *)(v42 + 39);
              v44 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
              v46 = v44(v8, v9, v155 + 17, v44, v43, v45, 0x310010676ADLL, 24466, 17364, v43, v164);
              *(_QWORD *)(v153 - 88) = v46;
              if ( (v46 & 1) == 0 || *(_DWORD *)(v46 - 1) > 0x425u )
                goto LABEL_181;
              v9 = 0x3100106770DLL;
              n23425149 = MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
              if ( (_DWORD)n23425149 != 23425149
                && ((n23425149 & 1) == 0
                 || *(_DWORD *)(n23425149 - 1) > 0x425u
                 || *(_DWORD *)(n23425149 + 7) != 20
                 || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
              {
                goto LABEL_182;
              }
              v9 = 0x3100106770DLL;
              MEMORY[0xFFFFFFFF9FFF77C0](v8, 0x3100106770DLL, 0x7FF62AF86780LL, 1);
              goto LABEL_61;
            }
          }
        }
        else if ( (_DWORD)n113_1 )
        {
          goto LABEL_34;
        }
        v49 = *(_QWORD *)(v153 - 48);
        v50 = *(int *)(v49 + 43) >> 1;
        if ( !v50 )
          goto LABEL_183;
        v51 = (unsigned int)-v50;
        if ( __OFSUB__((_DWORD)v51, 1) )
          goto LABEL_183;
        if ( __OFADD__((_DWORD)v51, (_DWORD)v51) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, edx }
          v146 = v154[10];
          if ( (unsigned __int64)(v146 + 12) >= v154[11] )
          {
            sub_3CC175(v49, v51);
          }
          else
          {
            v154[10] = v146 + 12;
            sub_3CBECB(v8, v146 + 1);
          }
          return;
        }
        v8 = *(_QWORD *)(v153 - 40);
        v9 = *(_QWORD *)(v153 - 32);
        v167 = v155 + *(unsigned int *)(v49 + 47);
        v52 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
        v53 = v52(
                v8,
                v9,
                v155 + 17,
                v52,
                (unsigned int)(2 * v51),
                v27,
                0x310010676ADLL,
                (unsigned int)(2 * v51),
                4890,
                5936,
                v167);
        *(_QWORD *)(v153 - 88) = v53;
        if ( (v53 & 1) == 0 || *(_DWORD *)(v53 - 1) > 0x425u )
          goto LABEL_184;
        MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
        v9 = 0x3100106770DLL;
        n23425149_1 = MEMORY[0xFFFFFFFFA00AC040](v8, 0x3100106770DLL);
        if ( (_DWORD)n23425149_1 != 23425149
          && ((n23425149_1 & 1) == 0
           || *(_DWORD *)(n23425149_1 - 1) > 0x425u
           || *(_DWORD *)(n23425149_1 + 7) != 20
           || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
        {
          goto LABEL_185;
        }
        v57 = v154[10];
        if ( (unsigned __int64)(v57 + 16) >= v154[11] )
        {
          v8 = MEMORY[0xFFFFFFFF9FFF7E80](v57, 0x3100106770DLL, 16);
        }
        else
        {
          v154[10] = v57 + 16;
          v8 = v57 + 1;
        }
        *(_DWORD *)(v8 - 1) = 32771877;
        *(_DWORD *)(v8 + 3) = v155 + 2021;
        *(_DWORD *)(v8 + 7) = v155 + 2021;
        *(_DWORD *)(v8 + 11) = v155 + 720893;
        *(_DWORD *)(v8 + 11) = v155 + 113;
        v9 = 0x3100106770DLL;
        MEMORY[0xFFFFFFFF9FFF77C0](
          v8,
          0x3100106770DLL,
          *(_QWORD *)((char *)&loc_3CB0E6 + 2),
          2,
          v55,
          v56,
          *(_QWORD *)(v153 - 96),
          v155 + 113,
          v8);
LABEL_61:
        v58 = *(_QWORD *)(v153 - 80);
        if ( (v58 & 1) != 0 )
          goto LABEL_186;
        v59 = (int)v58 >> 1;
        v60 = __OFADD__(1, v59);
        v61 = v59 + 1;
        if ( v60 )
          goto LABEL_187;
        *(_QWORD *)(v153 - 128) = v61;
        v62 = *(_QWORD *)(v153 - 48);
        v63 = v155 + *(unsigned int *)(v62 + 59);
        v64 = v155 + *(unsigned int *)(v62 + 63);
        v8 = *(unsigned int *)(v62 + 67);
        v9 = (unsigned int)((int)v8 >> 1);
        if ( !(_DWORD)v9 )
          goto LABEL_188;
        v9 = (unsigned int)-(int)v9;
        if ( __OFSUB__((_DWORD)v9, 1) )
          goto LABEL_188;
        if ( __OFADD__((_DWORD)v9, (_DWORD)v9) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, esi }
          v148 = v154[10];
          if ( (unsigned __int64)(v148 + 12) >= v154[11] )
          {
            sub_3CC1A0(v148, v9, v63, v62, v48);
          }
          else
          {
            v154[10] = v148 + 12;
            sub_3CBF3B(v148 + 1);
          }
          return;
        }
        v65 = v155 + *(unsigned int *)(v62 + 59);
        v66 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64, _QWORD))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
        *(_QWORD *)(v153 - 88) = v66(
                                   *(_QWORD *)(v153 - 56),
                                   *(_QWORD *)(v153 - 32),
                                   v155 + 17,
                                   v66,
                                   (unsigned int)(2 * v9),
                                   v65,
                                   0x310010676ADLL,
                                   6432,
                                   v65,
                                   v64,
                                   (unsigned int)(2 * v9));
        v67 = *(_QWORD *)(v153 - 48);
        v68 = *(_QWORD *)(v153 - 40);
        v69 = v155 + *(unsigned int *)(v67 + 71);
        v162 = v155 + *(unsigned int *)(v67 + 75);
        v70 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
        v72 = v70(
                v68,
                *(_QWORD *)(v153 - 32),
                v155 + 17,
                v70,
                v69,
                v71,
                0x310010676ADLL,
                v69,
                v162,
                10538,
                4294966468LL);
        *(_QWORD *)(v153 - 104) = v72;
        v73 = *(_QWORD *)(v153 - 88);
        if ( (v73 & 1) == 0 || *(_DWORD *)(v73 - 1) > 0x425u )
          goto LABEL_189;
        if ( (v72 & 1) == 0 || *(_DWORD *)(v72 - 1) > 0x425u )
          goto LABEL_190;
        n18536041 = MEMORY[0xFFFFFFFFA00AC040](v68, 0x3100106770DLL);
        if ( (_DWORD)n18536041 != 18536041
          && ((n18536041 & 1) == 0
           || *(_DWORD *)(n18536041 - 1) > 0x425u
           || *(_DWORD *)(n18536041 + 7) != 11
           || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
        {
          goto LABEL_191;
        }
        *(_QWORD *)(v153 - 104) = MEMORY[0xFFFFFFFF9FFF77C0](v68, 0x3100106770DLL, 0x7FF6287EAE50LL, 0);
        v75 = *(_QWORD *)(v153 - 48);
        v76 = *(_QWORD *)(v153 - 40);
        v77 = v155 + *(unsigned int *)(v75 + 79);
        v159 = v155 + *(unsigned int *)(v75 + 83);
        v78 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
        v80 = v78(v76, *(_QWORD *)(v153 - 32), v155 + 17, v78, v77, v79, 0x310010676ADLL, v77, v159, 7290, 29354);
        if ( (_DWORD)v80 != (_DWORD)byte_238D5D
          && ((v80 & 1) == 0
           || *(_DWORD *)(v80 - 1) > 0x425u
           || *(_DWORD *)(v80 + 7) != 4
           || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
        {
          goto LABEL_192;
        }
        *(_QWORD *)(v153 - 88) = MEMORY[0xFFFFFFFFA0046FC0](v76, *(_QWORD *)(v153 - 32), *(_QWORD *)(v153 - 104), 208);
        v81 = *(_QWORD *)(v153 - 48);
        v82 = *(int *)(v81 + 87) >> 1;
        if ( !v82 )
          goto LABEL_193;
        v83 = (unsigned int)-v82;
        if ( __OFSUB__((_DWORD)v83, 1) )
          goto LABEL_193;
        v84 = *(int *)(v81 + 91) >> 1;
        if ( !v84 )
          goto LABEL_194;
        v85 = -v84;
        if ( __OFSUB__(v85, 1) )
          goto LABEL_194;
        v152 = (unsigned int)(2 * v83);
        if ( __OFADD__((_DWORD)v83, (_DWORD)v83) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, edx }
          v150 = v154[10] + 12LL;
          if ( v150 >= v154[11] )
          {
            sub_3CC1CD(v81, v83);
          }
          else
          {
            v154[10] = v150;
            sub_3CBFC4();
          }
          return;
        }
        _RDX = (unsigned int)(2 * v85);
        if ( __OFADD__(v85, v85) )
        {
          __asm { vcvtsi2sd xmm15, xmm15, esi }
          v151 = v154[10];
          if ( (unsigned __int64)(v151 + 12) >= v154[11] )
          {
            sub_3CC1F8(v81, v151);
            return;
          }
          v154[10] = v151 + 12;
          _RDX = v151 + 1;
          goto LABEL_1;
        }
        goto LABEL_84;
      }
      if ( n1301_1 == 1341 && (*(_DWORD *)(n0x71 + 3) & 0xFFFFFF00) == 0 )
        goto LABEL_29;
    }
    else if ( !(_DWORD)n0x71 )
    {
      goto LABEL_29;
    }
LABEL_95:
    v103 = *(_QWORD *)(v153 - 80);
  }
  v105 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
  *(_QWORD *)(v153 - 72) = v105(
                             *(_QWORD *)(v153 - 40),
                             *(_QWORD *)(v153 - 32),
                             v155 + 17,
                             v105,
                             v11,
                             v12,
                             0x310010676ADLL,
                             v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 143LL),
                             v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 147LL),
                             14602,
                             18554);
  v106 = *(_QWORD *)(v153 - 56);
  v107 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  v110 = v107(
           v106,
           *(_QWORD *)(v153 - 32),
           v155 + 17,
           v107,
           v108,
           v109,
           0x310010676ADLL,
           11268,
           22500,
           26240,
           v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 151LL));
  v111 = *(_QWORD *)(v153 - 72);
  if ( (v111 & 1) == 0 || *(_DWORD *)(v111 - 1) > 0x425u )
    goto LABEL_199;
  if ( (v110 & 1) == 0 || *(_DWORD *)(v110 - 1) > 0x425u )
    goto LABEL_200;
  *(_QWORD *)(v153 - 96) = MEMORY[0xFFFFFFFFA00AC040](v106, 0x3100106770DLL);
  v112 = *(_QWORD *)(v153 - 48);
  v113 = *(_QWORD *)(v153 - 40);
  v114 = v155 + *(unsigned int *)(v112 + 155);
  v166 = v155 + *(unsigned int *)(v112 + 159);
  v115 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
  v117 = v115(v113, *(_QWORD *)(v153 - 32), v155 + 17, v115, v114, v116, 0x310010676ADLL, v114, v166, 15624, 30508);
  if ( (v117 & 1) == 0 || *(_DWORD *)(v117 - 1) > 0x425u )
    goto LABEL_201;
  *(_QWORD *)(v153 - 72) = MEMORY[0xFFFFFFFFA00AC040](v113, 0x3100106770DLL);
  v118 = *(_QWORD *)(v153 - 48);
  v119 = *(_QWORD *)(v153 - 56);
  v120 = v155 + *(unsigned int *)(v118 + 163);
  v163 = v155 + *(unsigned int *)(v118 + 167);
  v121 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  v123 = v121(v119, *(_QWORD *)(v153 - 32), v155 + 17, v121, v120, v122, 0x310010676ADLL, v120, v163, 12976, 12762);
  if ( (v123 & 1) == 0 || *(_DWORD *)(v123 - 1) > 0x425u )
    goto LABEL_202;
  MEMORY[0xFFFFFFFFA00AC040](v119, 0x3100106770DLL);
  MEMORY[0xFFFFFFFFA00AC040](v119, 0x3100106770DLL);
  *(_QWORD *)(v153 - 72) = MEMORY[0xFFFFFFFFA0102840](v119, *(_QWORD *)(v153 - 32));
  v124 = *(_QWORD *)(v153 - 56);
  v125 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  v128 = v125(
           v124,
           *(_QWORD *)(v153 - 32),
           v155 + 17,
           v125,
           v126,
           v127,
           0x310010676ADLL,
           1998,
           4034,
           4294962518LL,
           v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 171LL));
  *(_QWORD *)(v153 - 96) = v128;
  if ( (v128 & 1) == 0 || *(_DWORD *)(v128 - 1) > 0x425u )
    goto LABEL_203;
  MEMORY[0xFFFFFFFFA00AC040](v124, 0x3100106770DLL);
  v129 = *(_QWORD *)(v153 - 72);
  if ( (v129 & 1) == 0 || *(_DWORD *)(v129 - 1) > 0x425u )
    goto LABEL_204;
  *(_QWORD *)(v153 - 96) = MEMORY[0xFFFFFFFFA00AC040](v124, 0x3100106770DLL);
  v130 = *(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)byte_1CCD00 >> 8));
  n22129 = v130(
             *(_QWORD *)(v153 - 56),
             *(_QWORD *)(v153 - 32),
             v155 + 17,
             v130,
             v131,
             v132,
             0x310010676ADLL,
             4294964328LL,
             3012,
             v155 + *(unsigned int *)(*(_QWORD *)(v153 - 48) + 175LL),
             4294964220LL);
  if ( (_DWORD)n22129 != 22129
    && ((n22129 & 1) == 0
     || *(_DWORD *)(n22129 - 1) > 0x425u
     || *(_DWORD *)(n22129 + 7) != 4
     || (unsigned int)MEMORY[0xFFFFFFFF9FFF3000]() != 113) )
  {
    goto LABEL_205;
  }
  MEMORY[0xFFFFFFFFA008D940](0x31001094899LL, 0x3100106770DLL, v155 + 17);
  *(_QWORD *)(v153 - 56) = MEMORY[0xFFFFFFFFA0102840](0x31001094899LL, *(_QWORD *)(v153 - 32));
  v134 = *(_QWORD *)(v153 - 48);
  v135 = *(_QWORD *)(v153 - 40);
  v136 = v155 + *(unsigned int *)(v134 + 187);
  v137 = v155 + *(unsigned int *)(v134 + 179);
  v161 = v155 + *(unsigned int *)(v134 + 191);
  v160 = v155 + *(unsigned int *)(v134 + 183);
  v138 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(v154[84] + 16 * ((unsigned int)qword_1CC600 >> 8));
  v139 = v138(v135, *(_QWORD *)(v153 - 32), v155 + 17, v138, v136, v137, 0x310010676ADLL, v137, v160, v136, v161);
  *(_QWORD *)(v153 - 48) = v139;
  if ( (v139 & 1) == 0 || *(_DWORD *)(v139 - 1) > 0x425u )
    goto LABEL_206;
  MEMORY[0xFFFFFFFFA00AC040](v135, 0x3100106770DLL);
  v140 = *(_QWORD *)(v153 - 56);
  if ( (v140 & 1) == 0 || *(_DWORD *)(v140 - 1) > 0x425u )
    goto LABEL_207;
  MEMORY[0xFFFFFFFFA00AC040](v135, 0x3100106770DLL);
  MEMORY[0xFFFFFFFFA0102840](v135, *(_QWORD *)(v153 - 32));
  (*(void (__fastcall **)(__int64, __int64, __int64))(v154[84] + 315968LL))(0x31001D635A1LL, 0x310020349D9LL, v155 + 17);
  v104 = MEMORY[0x31001B1CE84] < 1142;
  MEMORY[0x31001B1CE84] -= 1142;
  if ( v104 )
    MEMORY[0xFFFFFFFFA00ABBC0](0x31001D635A1LL, 0x3100106770DLL);
}


//==== sub_3CC054 @ 0x3cc054
void __fastcall sub_3CC054()
{
  *(_DWORD *)(_RBX - 1) = 1301;
  __asm { vmovsd  qword ptr [rbx+3], xmm15 }
  JUMPOUT(0x3CB691);
}


//==== sub_3CC115 @ 0x3cc115
void __fastcall sub_3CC115(__int64 a1, __int64 a2)
{
  __int64 _RDI; // rax

  __asm { vmovsd  [rsp+30h+var_30], xmm15 }
  _RDI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+30h+var_30] }
  sub_3CBE3A(_RDI);
}


//==== sub_3CC146 @ 0x3cc146
void __fastcall sub_3CC146(__int64 a1, __int64 a2)
{
  __int64 _RSI; // rax

  __asm { vmovsd  [rsp+30h+var_30], xmm15 }
  _RSI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+30h+var_30] }
  sub_3CBE6E(a1, _RSI);
}


//==== sub_3CC175 @ 0x3cc175
void __fastcall sub_3CC175(__int64 a1, __int64 a2)
{
  __int64 _RSI; // rax

  __asm { vmovsd  [rsp+20h+var_20], xmm15 }
  _RSI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+20h+var_20] }
  sub_3CBECB(a1, _RSI);
}


//==== sub_3CC1A0 @ 0x3cc1a0
void __fastcall sub_3CC1A0(__int64 a1, __int64 a2)
{
  __int64 _RDI; // rax

  __asm { vmovsd  [rsp+28h+var_28], xmm15 }
  _RDI = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+28h+var_28] }
  sub_3CBF3B(_RDI);
}


//==== sub_3CC1CD @ 0x3cc1cd
void __fastcall sub_3CC1CD(__int64 a1, __int64 a2)
{
  __asm { vmovsd  [rsp+20h+var_20], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+20h+var_20] }
  sub_3CBFC4();
}


//==== sub_3CC1F8 @ 0x3cc1f8
void __fastcall sub_3CC1F8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 _RDX; // rax
  __int64 v11; // r8
  __int64 v12; // r9

  __asm { vmovsd  [rsp+20h+var_20], xmm15 }
  _RDX = MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+20h+var_20] }
  sub_3CBFF7(a1, a2, _RDX, a4, v11, v12, a7, a8);
}


//==== sub_3CC223 @ 0x3cc223
void __fastcall sub_3CC223(__int64 a1, __int64 a2)
{
  __asm { vmovsd  [rsp+8+var_8], xmm15 }
  MEMORY[0xFFFFFFFF9FFF7E80](a1, a2, 12);
  __asm { vmovsd  xmm15, [rsp+8+var_8] }
  sub_3CC054();
}


//==== sub_3E10B0 @ 0x3e10b0
__int64 __fastcall sub_3E10B0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41)
{
  return MEMORY[0x150117D52500000A];
}


//==== sub_471370 @ 0x471370
__int64 __fastcall sub_471370(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        __int64 a34,
        __int64 a35,
        __int64 a36,
        __int64 a37,
        __int64 a38,
        __int64 a39,
        __int64 a40,
        __int64 a41,
        __int64 a42,
        __int64 a43,
        __int64 a44,
        __int64 a45,
        __int64 a46,
        __int64 a47,
        __int64 a48,
        __int64 a49,
        __int64 a50)
{
  return MEMORY[0x39015AD54900000A];
}


