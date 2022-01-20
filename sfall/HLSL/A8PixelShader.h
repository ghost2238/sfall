#if 0

//listing of all techniques and passes with embedded asm listings 

technique T1
{
    pass p1
    {
        //No embedded vertex shader
        pixelshader = 
            asm {
            //
            // Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
            //
            // Parameters:
            //
            //   int showhl;
            //   float2 size;
            //   float2 sizehl;
            //
            //
            // Registers:
            //
            //   Name         Reg   Size
            //   ------------ ----- ----
            //   size         c0       1
            //   sizehl       c1       1
            //   showhl       c2       1
            //
            
                preshader
                rcp c0.x, c0.x
                rcp c0.y, c0.y
                mul c1.x, c2.x, c2.x
                rcp c2.x, c1.x
                rcp c2.y, c1.y
            
            // approximately 5 instructions used
            //
            // Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
            //
            // Parameters:
            //
            //   float2 corner;
            //   float2 cornerhl;
            //   sampler2D s0;
            //   sampler2D s1;
            //   sampler2D s2;
            //   sampler2D s3;
            //
            //
            // Registers:
            //
            //   Name         Reg   Size
            //   ------------ ----- ----
            //   corner       c3       1
            //   cornerhl     c4       1
            //   s0           s0       1
            //   s1           s1       1
            //   s2           s2       1
            //   s3           s3       1
            //
            
                ps_2_0
                def c5, -1, -0.00100000005, 1, 0
                dcl t0.xy
                dcl_2d s0
                dcl_2d s1
                dcl_2d s2
                dcl_2d s3
                texld r0, t0, s0
                add r0.xy, t0, -c3
                mul_sat r0.xy, r0, c0
                mov r1.xy, r0.w
                add r1.zw, t0.wzyx, -c4.wzyx
                mul_sat r2.xy, r1.wzyx, c2
                texld r3, r0, s2
                texld r1, r1, s1
                texld r2, r2, s3
                add r1.w, r0.w, c5.x
                abs r1.w, r1.w
                add r1.w, r1.w, c5.y
                cmp r0.xyz, r1.w, r1, r3
                add_sat r1.xyz, r2, r0
                cmp r0.xyz, -c1.x, r0, r1
                mov r0.w, c5.z
                mov oC0, r0
            
            // approximately 17 instruction slots used (4 texture, 13 arithmetic)
            };
    }
}

technique T0
{
    pass p0
    {
        //No embedded vertex shader
        pixelshader = 
            asm {
            //
            // Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
            //
            // Parameters:
            //
            //   sampler2D s0;
            //   sampler2D s1;
            //
            //
            // Registers:
            //
            //   Name         Reg   Size
            //   ------------ ----- ----
            //   s0           s0       1
            //   s1           s1       1
            //
            
                ps_2_0
                def c0, 1, 0, 0, 0
                dcl t0.xy
                dcl_2d s0
                dcl_2d s1
                texld r0, t0, s0
                mov r0.xy, r0.w
                texld r0, r0, s1
                mov r0.w, c0.x
                mov oC0, r0
            
            // approximately 5 instruction slots used (2 texture, 3 arithmetic)
            };
    }
}

#endif

const BYTE gpuEffectA8[] =
{
      1,   9, 255, 254,  56,   5, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0,  28,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      6,   0,   0,   0, 105, 109, 
     97, 103, 101,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0,  64,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      8,   0,   0,   0, 112,  97, 
    108, 101, 116, 116, 101,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 100,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      5,   0,   0,   0, 104, 101, 
     97, 100,   0,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 136,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     10,   0,   0,   0, 104, 105, 
    103, 104, 108, 105, 103, 104, 
    116,   0,   0,   0,  10,   0, 
      0,   0,   4,   0,   0,   0, 
    216,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 164,   0, 
      0,   0,   0,   1,   0,   0, 
    176,   0,   0,   0, 172,   0, 
      0,   0,   3,   0,   0,   0, 
    115,  48,   0,   0,  10,   0, 
      0,   0,   4,   0,   0,   0, 
    224,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   5,   0,   0,   0, 
    164,   0,   0,   0,   0,   1, 
      0,   0, 248,   0,   0,   0, 
    244,   0,   0,   0, 170,   0, 
      0,   0,   0,   1,   0,   0, 
     16,   1,   0,   0,  12,   1, 
      0,   0, 169,   0,   0,   0, 
      0,   1,   0,   0,  48,   1, 
      0,   0,  44,   1,   0,   0, 
    165,   0,   0,   0,   0,   1, 
      0,   0,  80,   1,   0,   0, 
     76,   1,   0,   0, 166,   0, 
      0,   0,   0,   1,   0,   0, 
    112,   1,   0,   0, 108,   1, 
      0,   0,   3,   0,   0,   0, 
    115,  49,   0,   0,  10,   0, 
      0,   0,   4,   0,   0,   0, 
    232,   2,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   5,   0,   0,   0, 
    164,   0,   0,   0,   0,   1, 
      0,   0,   0,   2,   0,   0, 
    252,   1,   0,   0, 170,   0, 
      0,   0,   0,   1,   0,   0, 
     24,   2,   0,   0,  20,   2, 
      0,   0, 169,   0,   0,   0, 
      0,   1,   0,   0,  56,   2, 
      0,   0,  52,   2,   0,   0, 
    165,   0,   0,   0,   0,   1, 
      0,   0,  88,   2,   0,   0, 
     84,   2,   0,   0, 166,   0, 
      0,   0,   0,   1,   0,   0, 
    120,   2,   0,   0, 116,   2, 
      0,   0,   3,   0,   0,   0, 
    115,  50,   0,   0,  10,   0, 
      0,   0,   4,   0,   0,   0, 
    240,   3,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   5,   0,   0,   0, 
    164,   0,   0,   0,   0,   1, 
      0,   0,   8,   3,   0,   0, 
      4,   3,   0,   0, 170,   0, 
      0,   0,   0,   1,   0,   0, 
     32,   3,   0,   0,  28,   3, 
      0,   0, 169,   0,   0,   0, 
      0,   1,   0,   0,  64,   3, 
      0,   0,  60,   3,   0,   0, 
    165,   0,   0,   0,   0,   1, 
      0,   0,  96,   3,   0,   0, 
     92,   3,   0,   0, 166,   0, 
      0,   0,   0,   1,   0,   0, 
    128,   3,   0,   0, 124,   3, 
      0,   0,   3,   0,   0,   0, 
    115,  51,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     28,   4,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0, 115, 105, 122, 101, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     76,   4,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  99, 111, 114, 110, 
    101, 114,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
    124,   4,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0, 115, 105, 122, 101, 
    104, 108,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
    172,   4,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  99, 111, 114, 110, 
    101, 114, 104, 108,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0, 220,   4, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0, 115, 104, 111, 119, 
    104, 108,   0,   0,   9,   0, 
      0,   0,  15,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0, 112,  49,   0,   0, 
      3,   0,   0,   0,  84,  49, 
      0,   0,  10,   0,   0,   0, 
     15,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
    112,  48,   0,   0,   3,   0, 
      0,   0,  84,  48,   0,   0, 
     13,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
     11,   0,   0,   0,   4,   0, 
      0,   0,  24,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  40,   0,   0,   0, 
     60,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     76,   0,   0,   0,  96,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 112,   0, 
      0,   0, 132,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 152,   0,   0,   0, 
    196,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    224,   0,   0,   0, 140,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 232,   1, 
      0,   0, 148,   2,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 240,   2,   0,   0, 
    156,   3,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    248,   3,   0,   0,  20,   4, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  40,   4, 
      0,   0,  68,   4,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  88,   4,   0,   0, 
    116,   4,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    136,   4,   0,   0, 164,   4, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 188,   4, 
      0,   0, 216,   4,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   8,   5,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   5,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0, 147,   0,   0,   0, 
      0,   0,   0,   0, 236,   4, 
      0,   0, 232,   4,   0,   0, 
     48,   5,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     40,   5,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
    147,   0,   0,   0,   0,   0, 
      0,   0,  20,   5,   0,   0, 
     16,   5,   0,   0,   4,   0, 
      0,   0,   6,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      0,   0,   0,   0,  52,   1, 
      0,   0,   0,   2, 255, 255, 
    254, 255,  42,   0,  67,  84, 
     65,  66,  28,   0,   0,   0, 
    115,   0,   0,   0,   0,   2, 
    255, 255,   2,   0,   0,   0, 
     28,   0,   0,   0,   0,   0, 
      0,  32, 108,   0,   0,   0, 
     68,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     72,   0,   0,   0,   0,   0, 
      0,   0,  88,   0,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0,  92,   0,   0,   0, 
      0,   0,   0,   0, 115,  48, 
      0, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    115,  49,   0, 171,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 112, 115,  95,  50, 
     95,  48,   0,  77, 105,  99, 
    114, 111, 115, 111, 102, 116, 
     32,  40,  82,  41,  32,  72, 
     76,  83,  76,  32,  83, 104, 
     97, 100, 101, 114,  32,  67, 
    111, 109, 112, 105, 108, 101, 
    114,  32,  57,  46,  50,  57, 
     46,  57,  53,  50,  46,  51, 
     49,  49,  49,   0,  81,   0, 
      0,   5,   0,   0,  15, 160, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      0,   0,   3, 176,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      0,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      1,   8,  15, 160,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 176,   0,   8, 
    228, 160,   1,   0,   0,   2, 
      0,   0,   3, 128,   0,   0, 
    255, 128,  66,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,   1,   8, 228, 160, 
      1,   0,   0,   2,   0,   0, 
      8, 128,   0,   0,   0, 160, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    180,   4,   0,   0,   0,   2, 
    255, 255, 254, 255,  84,   0, 
     67,  84,  65,  66,  28,   0, 
      0,   0,  27,   1,   0,   0, 
      0,   2, 255, 255,   6,   0, 
      0,   0,  28,   0,   0,   0, 
      0,   0,   0,  32,  20,   1, 
      0,   0, 148,   0,   0,   0, 
      2,   0,   3,   0,   1,   0, 
      0,   0, 156,   0,   0,   0, 
    172,   0,   0,   0, 188,   0, 
      0,   0,   2,   0,   4,   0, 
      1,   0,   0,   0, 156,   0, 
      0,   0, 172,   0,   0,   0, 
    197,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
    200,   0,   0,   0,   0,   0, 
      0,   0, 216,   0,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0, 220,   0,   0,   0, 
      0,   0,   0,   0, 236,   0, 
      0,   0,   3,   0,   2,   0, 
      1,   0,   0,   0, 240,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,   3,   0, 
      3,   0,   1,   0,   0,   0, 
      4,   1,   0,   0,   0,   0, 
      0,   0,  99, 111, 114, 110, 
    101, 114,   0, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     99, 111, 114, 110, 101, 114, 
    104, 108,   0, 115,  48,   0, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 115,  49, 
      0, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    115,  50,   0, 171,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 115,  51,   0, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 112, 115, 
     95,  50,  95,  48,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  57,  46, 
     50,  57,  46,  57,  53,  50, 
     46,  51,  49,  49,  49,   0, 
    254, 255, 126,   0,  80,  82, 
     69,  83,   1,   2,  88,  70, 
    254, 255,  58,   0,  67,  84, 
     65,  66,  28,   0,   0,   0, 
    179,   0,   0,   0,   1,   2, 
     88,  70,   3,   0,   0,   0, 
     28,   0,   0,   0,   0,   1, 
      0,  32, 176,   0,   0,   0, 
     88,   0,   0,   0,   2,   0, 
      2,   0,   1,   0,   0,   0, 
     96,   0,   0,   0, 112,   0, 
      0,   0, 128,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0, 136,   0,   0,   0, 
    112,   0,   0,   0, 152,   0, 
      0,   0,   2,   0,   1,   0, 
      1,   0,   0,   0, 160,   0, 
      0,   0, 112,   0,   0,   0, 
    115, 104, 111, 119, 104, 108, 
      0, 171,   0,   0,   2,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 115, 105, 
    122, 101,   0, 171, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      2,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 115, 105, 
    122, 101, 104, 108,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      2,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 116, 120, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  50,  57,  46,  57, 
     53,  50,  46,  51,  49,  49, 
     49,   0, 254, 255,  12,   0, 
     80,  82,  83,  73,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    254, 255,   2,   0,  67,  76, 
     73,  84,   0,   0,   0,   0, 
    254, 255,  47,   0,  70,  88, 
     76,  67,   5,   0,   0,   0, 
      1,   0,  48,  16,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,  48,  16, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
     80, 160,   2,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   4,   0,   0,   0, 
      1,   0,  48,  16,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   8,   0, 
      0,   0,   1,   0,  48,  16, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      9,   0,   0,   0, 240, 240, 
    240, 240,  15,  15,  15,  15, 
    255, 255,   0,   0,  81,   0, 
      0,   5,   5,   0,  15, 160, 
      0,   0, 128, 191, 111,  18, 
    131, 186,   0,   0, 128,  63, 
      0,   0,   0,   0,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      0,   0,   3, 176,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      0,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      1,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      2,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      3,   8,  15, 160,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 176,   0,   8, 
    228, 160,   2,   0,   0,   3, 
      0,   0,   3, 128,   0,   0, 
    228, 176,   3,   0, 228, 161, 
      5,   0,   0,   3,   0,   0, 
     19, 128,   0,   0, 228, 128, 
      0,   0, 228, 160,   1,   0, 
      0,   2,   1,   0,   3, 128, 
      0,   0, 255, 128,   2,   0, 
      0,   3,   1,   0,  12, 128, 
      0,   0,  27, 176,   4,   0, 
     27, 161,   5,   0,   0,   3, 
      2,   0,  19, 128,   1,   0, 
     27, 128,   2,   0, 228, 160, 
     66,   0,   0,   3,   3,   0, 
     15, 128,   0,   0, 228, 128, 
      2,   8, 228, 160,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   1,   8, 
    228, 160,  66,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,   3,   8, 228, 160, 
      2,   0,   0,   3,   1,   0, 
      8, 128,   0,   0, 255, 128, 
      5,   0,   0, 160,  35,   0, 
      0,   2,   1,   0,   8, 128, 
      1,   0, 255, 128,   2,   0, 
      0,   3,   1,   0,   8, 128, 
      1,   0, 255, 128,   5,   0, 
     85, 160,  88,   0,   0,   4, 
      0,   0,   7, 128,   1,   0, 
    255, 128,   1,   0, 228, 128, 
      3,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,  23, 128, 
      2,   0, 228, 128,   0,   0, 
    228, 128,  88,   0,   0,   4, 
      0,   0,   7, 128,   1,   0, 
      0, 161,   0,   0, 228, 128, 
      1,   0, 228, 128,   1,   0, 
      0,   2,   0,   0,   8, 128, 
      5,   0, 170, 160,   1,   0, 
      0,   2,   0,   8,  15, 128, 
      0,   0, 228, 128, 255, 255, 
      0,   0, 255, 255, 255, 255, 
      7,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  10,   0, 
      0,   0, 104, 105, 103, 104, 
    108, 105, 103, 104, 116,   0, 
      0,   0, 255, 255, 255, 255, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   5,   0, 
      0,   0, 104, 101,  97, 100, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   5,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0, 112,  97, 
    108, 101, 116, 116, 101,   0, 
    255, 255, 255, 255,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   6,   0,   0,   0, 
    105, 109,  97, 103, 101,   0, 
      0,   0
};
