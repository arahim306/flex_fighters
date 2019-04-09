library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;
use work.vga_lib.all;

entity SRAM_block_sel_gen is
	port (
		Video_On 			: in std_logic;
		player_num			: in std_logic;
		brick_en 			: in std_logic;
		game_state			: in std_logic_vector(1 downto 0);
		l_boxer_state		: in std_logic_vector(1 downto 0);
		r_boxer_state		: in std_logic_vector(1 downto 0);
		sram_block_sel 		: out std_logic_vector(3 downto 0)
	);
end SRAM_block_sel_gen;

architecture BHV of SRAM_block_sel_gen is
begin
	process(player_num, Video_On, game_state, l_boxer_state, r_boxer_state)
	begin

		-- check video_on enable
		if(Video_On = '1') then

			-- check game state
			if(game_state = "00") then -- if in menu state
				sram_block_sel <= "0000";

			elsif(game_state = "01") then -- if in calibration state
				sram_block_sel <= "0000";

			elsif(game_state = "10") then -- if in fight state

				if(brick_en = '1') then -- if rendering bricks
					sram_block_sel <= "1000";

				elsif(player_num = '0') then -- if left boxer
					-- read boxer select lines and determine sram block
					if(l_boxer_state = "00") then 		-- standing
						sram_block_sel <= "0000";
					elsif(l_boxer_state	= "01") then 	-- right punch
						sram_block_sel <= "0001";
					elsif(l_boxer_state = "10") then	-- left punch
						sram_block_sel <= "0010";
					else 								-- hurt
						sram_block_sel <= "0011";
					end if;

				else -- if right boxer
					-- read boxer select lines and determine sram block
					if(r_boxer_state = "00") then 		-- standing
						sram_block_sel <= "0000";
					elsif(r_boxer_state	= "01") then 	-- right punch
						sram_block_sel <= "0001";
					elsif(r_boxer_state = "10") then	-- left punch
						sram_block_sel <= "0010";
					else 								-- hurt
						sram_block_sel <= "0011";
					end if;
				end if;
			else -- if in results state
				sram_block_sel <= "0000";
			end if;
		-- if no video_on, set default
		else
			sram_block_sel <= "0000";
		end if;
	end process;
end BHV;