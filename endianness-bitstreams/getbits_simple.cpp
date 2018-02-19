/* For the first example, we are going to assume a simple 
 * "Everything sequential in memory" (byte array) bitstream,
 * and ignore issues such as running in to the end of the
 * array. 
 */

#include <stdint.h>

// Treat buf[] as a giant little-endian integer, grab
// width bits starting at bit number pos. (LSB=bit 0).
uint64_t bit_extract_lsb(const uint8_t *buf, size_t pos, int width)
{
  assert(width >= 0 && width <= 64 - 7);
  
  // Read a 64-bit little-endian number starting from the byte
  // containing bit number pos (relative to buf)
  uint64_t bits = read64LE(&buf[pos / 8];
  
  // Shift out the bits inside the first byte that we've already
  // consumed.
  // After this, the LSB of our bitfield is in the LSB of bits
  bits >>= pos % 8;

  // Return the low width bits, zeroing the rest via a bit mask
  return bits & ((1lull << width) - 1);
}

// State variable, assumed to be local variables, or factored 
// into some object; hopefully not actual globals...
const uint8_t* bitstream;  // input bitstream
size_t bit_pos;  // current position in the stream

uint64_t getbits_extract_lsb(int width)
{
  // Read the bits
  unit64_t result = bit_extract_lsb(bitstream, bit_pos, width);
  // Advance the cursor
  bit_pos += width;
  return result;
}

