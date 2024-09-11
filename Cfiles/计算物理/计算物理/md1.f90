MODULE particles

!*****************************************************************************80
!
!! PARTICLES is a module for atom property data.
!
!  Modified:
!
!    01 November 2005
!
!  Parameters:
!
!    integer ( kind = 4 ) :: DIM, the spatial dimension.
!    Reasonable values are 2 or 3.
!
!    real ( kind = 8 ) :: ACC(N), the particle accelerations.
!
!    real ( kind = 8 ) :: BOX_SIZE(DIM), the length scale factor.
!
!    real ( kind = 8 ) :: COORD(N), the particle coordinations.
!
!    real ( kind = 8 ) :: DELTAR(N), the particle displacements.
!
!    real ( kind = 8 ) :: DENSITY, the density of the box.
!
!    real ( kind = 8 ) :: DERU(N), U'(n_i).
!
!    real ( kind = 8 ) :: ENE_KIN(N), the particle kinetic energies.
!
!    real ( kind = 8 ) :: ENE_POT(N), the particle potential energies.
!
!    integer :: N, the  number of particles.
!
!    real ( kind = 8 ) :: POS(N), the particle positions.
!
!    real ( kind = 8 ) :: VEL(N), the particle velocities.
!
!    logical :: VEL_ACC, is TRUE if the file includes velocities
!    and accelerations.
!
!    real ( kind = 8 ) :: VIRIAL, the virial term.
!
!    real ( kind = 8 ) :: VOLUME, the volume of the box.
!
    INTEGER(kind=4), PARAMETER :: dim = 3

    REAL(kind=8), DIMENSION(:, :), ALLOCATABLE :: acc
    REAL(kind=8), DIMENSION(dim) :: box_size
    REAL(kind=8), DIMENSION(:), ALLOCATABLE :: coord
    REAL(kind=8), DIMENSION(:, :), ALLOCATABLE :: deltar
    REAL(kind=8) :: density
    REAL(kind=8), DIMENSION(:), ALLOCATABLE :: deru
    REAL(kind=8), DIMENSION(:), ALLOCATABLE :: ene_kin
    REAL(kind=8), DIMENSION(:), ALLOCATABLE :: ene_pot
    INTEGER(kind=4) :: n = 0
    REAL(kind=8), DIMENSION(:, :), ALLOCATABLE :: pos
    REAL(kind=8), DIMENSION(:, :), ALLOCATABLE :: vel
    LOGICAL :: vel_acc = .FALSE.
    REAL(kind=8) :: virial
    REAL(kind=8) :: volume

END
MODULE simulation_control

!*****************************************************************************80
!
!! SIMULATION_CONTROL is a module for simulation control data.
!
!  Discussion:
!
!    This data is supplied from user input.
!
!  Modified:
!
!    31 October 2005
!
!  Parameters:
!
!    real ( kind = 8 ) :: DELTAT, the time steps, in reduced units.
!
!    character ( len = 80 ) :: SAMPIN, the name of the input file.
!
!    character ( len = 80 ) :: SAMPOUT, the name of the output file.
!
!    real ( kind = 8 ) :: SKIN, extra range for the neighbor list.
!    (used by MD3 and MD3GLUE only).
!
!    integer ( kind = 4 ) :: STEP_NUM, the number of time steps to do.
!
!    logical :: TEMP_CONSTANT, is TRUE if TEMP_REQUESTED is nonnegative.
!
!    real ( kind = 8 ) :: TEMP_REQUESTED, the desired temperature.  Any value
!    less than zero leaves it constant.
!
!    character ( len = 80 ) :: TITLE, an arbitrary title string.
!
!    real ( kind = 8 ) :: RHO_REQUESTED, the desired density.  A value
!    of 0 leaves it unchanged.
!
!    logical :: RHO_CHANGE, is TRUE if the user is changing the density.
!
!    real ( kind = 8 ) :: k_B, the Boltzmann constant.
!    (used by MD3GLUE only).
!
    REAL(kind=8) :: deltat
    CHARACTER(len=80) :: sampin
    CHARACTER(len=80) :: sampout
    REAL(kind=8) :: skin
    INTEGER(kind=4) :: step_num
    LOGICAL :: temp_constant
    REAL(kind=8) :: temp_requested
    CHARACTER(len=80) :: title
    REAL(kind=8) :: rho_requested
    LOGICAL :: rho_change
    REAL(kind=8), PARAMETER :: k_B = 8.617385D-05

END
MODULE potential

!*****************************************************************************80
!
!! POTENTIAL is a module with the parameters of the Lennard-Jones potential.
!
!  Modified:
!
!    02 November 2005
!
!  Parameters:
!
!    real ( kind = 8 ), R_CUTOFF, the cutoff distance.
!
!    real ( kind = 8 ), phicutoff, the value of the potential at the
!    cutoff distance.
!
!    integer ( kind = 4 ), TableSize, the size of the table.
!
!    real ( kind = 8 ), R_MIN
!
!    real ( kind = 8 ), rsqMin = R_MIN**2.
!
!    real ( kind = 8 ), DeltaRsq, the spacing in the table data, as a function
!    of radius squared.
!
!    real ( kind = 8 ), InvDeltaRsq = 1 / DeltaRsq.
!
!    real ( kind = 8 ), PhiTab, the tabulated value of the potential.
!
!    real ( kind = 8 ), DPhiTab, the value 1/r dphi/dr.
!
    REAL(kind=8), PARAMETER :: r_cutoff = 2.5D+00
    REAL(kind=8), PARAMETER :: r_min = 0.5D+00
    INTEGER(kind=4), PARAMETER :: TableSize = 20001
    REAL(kind=8), DIMENSION(TableSize) :: PhiTab
    REAL(kind=8), DIMENSION(TableSize) :: DPhiTab

    REAL(kind=8), PARAMETER :: phicutoff = &
                               4.0D+00 / (r_cutoff**12) - 4.0D+00 / (r_cutoff**6)
    REAL(kind=8), PARAMETER :: RsqMin = r_min**2

    REAL(kind=8), PARAMETER :: DeltaRsq = &
                               (r_cutoff**2 - RsqMin) / (TableSize - 1)

    REAL(kind=8), PARAMETER :: InvDeltaRsq = 1.0D+00 / DeltaRsq

END
PROGRAM main

!*****************************************************************************80
!
!! MAIN is the main program for MD1.
!
!  Discussion:
!
!    MD1 is a simple, minimal molecular dynamics program in Fortran90
!
!    MD1 uses the Lennard-Jones potential and the 'velocity' Verlet
!    time integration algorithm.
!
!    It computes kinetic and potential energy, density and pressure.
!
!    Files used by this program:
!
!    Unit  I/O  Meaning
!    ----  ---  ----------------------------------------------------------------
!      1    I   Input sample (coordinates, and perhaps also velocities and
!               accelerations) read at the beginning of the run
!      2    O   Output sample (coordinates, velocities, accelerations) written
!               at the end of the run
!      *    I   Standard input for the simulation control
!      *    O   Standard output containing various informations on the run
!
!    The standard output of this program is suitable to be directly fed to
!    'gnuplot' to produce plots as a function of time.  This is because
!    everything but data lines is commented out with an initial '#' character.
!
!  Modified:
!
!    09 January 2006
!
!  Author:
!
!    Furio Ercolessi
!
!  Reference:
!
!    MP Allen, DJ Tildsley,
!    Computer Simulation of Liquids,
!    Oxford University Press, 1987.
!
!    Furio Ercolessi,
!    A Molecular Dynamics Primer.
!
    USE particles

    IMPLICIT NONE

    CALL timestamp()
    WRITE (*, '(a)') ''
    WRITE (*, '(a)') 'MD1'
    WRITE (*, '(a)') '  FORTRAN90 version'
    WRITE (*, '(a)') '  A Molecular Dynamics simulation.'
    WRITE (*, '(a)') '  Last modified on 09 January 2006.'

    CALL initialize()

    CALL evolve_sample()
!
!  Write the final sample to a file.
!
    CALL write_sample()
!
!  Free memory.
!
    DEALLOCATE (acc)
    DEALLOCATE (ene_kin)
    DEALLOCATE (ene_pot)
    DEALLOCATE (pos)
    DEALLOCATE (vel)
!
!  Terminate.
!
    WRITE (*, '(a)') ''
    WRITE (*, '(a)') 'MD1:'
    WRITE (*, '(a)') '  Normal end of execution.'

    WRITE (*, '(a)') ''
    CALL timestamp()

    STOP
END
SUBROUTINE compute_forces()

!*****************************************************************************80
!
!! COMPUTE_FORCES computes the forces on atoms.
!
!  Discussion:
!
!    The forces are computed based on the atomic positions, using the
!    Lennard-Jones potential.
!    Note double nested loop, giving O(N^2) time: this is a SLOW ROUTINE,
!    unsuitable for large systems.
!
!  Modified:
!
!    28 October 2005
!
!  Author:
!
!    Furio Ercolessi
!
    USE particles
    USE potential

    IMPLICIT NONE

    REAL(kind=8) :: dphi
    INTEGER(kind=4) :: i
    INTEGER(kind=4) :: j
    REAL(kind=8) :: phi
    REAL(kind=8), DIMENSION(dim) :: rij
    REAL(kind=8) :: rm12
    REAL(kind=8) :: rm2
    REAL(kind=8) :: rm6
    REAL(kind=8) :: rsqij
    REAL(kind=8), DIMENSION(dim) :: sij
!
!  Reset to zero the potential energies, forces, virial term.
!
    ene_pot = 0.0D+00
    acc = 0.0D+00
    virial = 0.0D+00
!
!  Loop over all pairs of particles.
!
    DO i = 1, n - 1
        DO j = i + 1, n

            sij(1:dim) = pos(1:dim, i) - pos(1:dim, j)

            WHERE (0.5D+00 < ABS(sij))
                sij = sij - SIGN(1.0D+00, sij)
            END WHERE

            rij(1:dim) = box_size(1:dim) * sij(1:dim)

            rsqij = DOT_PRODUCT(rij(1:dim), rij(1:dim))
!
!  If the particles are close enough, compute the interaction.
!
            IF (rsqij < r_cutoff**2) THEN

                rm2 = 1.0D+00 / rsqij
                rm6 = rm2**3
                rm12 = rm6**2

                phi = 4.0D+00 * (rm12 - rm6) - phicutoff

                dphi = 24.0D+00 * rm2 * (2.0D+00 * rm12 - rm6)
!
!  Accumulate energy, virial, and forces.
!
                ene_pot(i) = ene_pot(i) + 0.5D+00 * phi
                ene_pot(j) = ene_pot(j) + 0.5D+00 * phi
                virial = virial - dphi * rsqij
                acc(1:dim, i) = acc(1:dim, i) + dphi * sij(1:dim)
                acc(1:dim, j) = acc(1:dim, j) - dphi * sij(1:dim)

            END IF

        END DO
    END DO
!
!  Definition of the virial term.
!
    virial = -virial / REAL(dim, kind=8)

    RETURN
END
SUBROUTINE compute_temperature(ene_kin_aver, temperature)

!*****************************************************************************80
!
!! COMPUTE_TEMPERATURE updates the kinetic energy and temperature.
!
!  Discussion:
!
!    Starting from the velocities currently stored in VEL, update
!    the kinetic energy array ENE_KIN, and compute ENE_KIN_AVER,
!    the average kinetic energy per particle, and the
!    instantaneous temperature.
!
!  Modified:
!
!    28 October 2005
!
!  Author:
!
!    Furio Ercolessi
!
!  Parameters:
!
!    Output, real ( kind = 8 ) ENE_KIN_AVER, the average kinetic
!    energy per particle.
!
!    Output, real ( kind = 8 ) TEMPERATURE, the instantaneous
!    temperature of the particle system.
!
    USE particles

    IMPLICIT NONE

    REAL(kind=8) :: ene_kin_aver
    INTEGER(kind=4) :: i
    REAL(kind=8), DIMENSION(dim) :: real_vel
    REAL(kind=8) :: temperature

    DO i = 1, n
        real_vel(1:dim) = box_size(1:dim) * vel(1:dim, i)
        ene_kin(i) = 0.5D+00 * DOT_PRODUCT(real_vel(1:dim), real_vel(1:dim))
    END DO

    ene_kin_aver = SUM(ene_kin(1:n)) / REAL(n, kind=8)

    temperature = 2.0D+00 * ene_kin_aver / REAL(dim, kind=8)

    RETURN
END
SUBROUTINE evolve_sample()

!*****************************************************************************80
!
!! EVOLVE_SAMPLE controls the time evolution of the system.
!
!  Modified:
!
!    26 May 2013
!
!  Author:
!
!    Furio Ercolessi
!
!  Local Parameters:
!
!    real ( kind = 8 ) ENE_KIN_SUM, the running sum of the kinetic energy.
!
!    real ( kind = 8 ) ENE_POT_SUM, the running sum of the potential energy.
!
!    real ( kind = 8 ) PRESSURE_SUM, the running sum of the pressure.
!
!    real ( kind = 8 ) TEMPERATURE_SUM, the running sum of the temperature.
!
    USE particles
    USE simulation_control

    IMPLICIT NONE

    REAL(kind=8) :: chi
    INTEGER(kind=4) command_unit
    CHARACTER(len=255) command_filename
    INTEGER(kind=4) data_unit
    CHARACTER(len=255) data_filename
    INTEGER(kind=4) traj_unit
    CHARACTER(len=255) traj_filename
    REAL(kind=8) :: ene_kin_aver
    REAL(kind=8) :: ene_kin_sum = 0.0D+00
    REAL(kind=8) :: ene_pot_aver
    REAL(kind=8) :: ene_pot_sum = 0.0D+00
    REAL(kind=8) :: ene_tot_aver
    REAL(kind=8) :: pressure
    REAL(kind=8) :: pressure_sum = 0.0D+00
    INTEGER(kind=4) step
    REAL(kind=8) :: temperature
    REAL(kind=8) :: temperature_sum = 0.0D+00
!
!  We need to have the initial temperature ready in case we are going
!  at constant T:
!
    CALL compute_temperature(ene_kin_aver, temperature)
!
!  "Velocity Verlet" integrator (see e.g. Allen and Tildesley book, p. 81).
!  Simple velocity scaling (done on velocities at the previous step)
!  applied when temp_constant is enabled.
!
    CALL get_unit(data_unit)
    data_filename = 'md1_data.txt'

    OPEN (unit=data_unit, file=data_filename, status='replace')

    CALL get_unit(traj_unit)
    traj_filename = 'md1_traj.xyz'
    OPEN (unit=traj_unit, file=traj_filename, status='replace')
!
!  Print headers of columns.
!
    WRITE (data_unit, '(a)') '#'
    WRITE (data_unit, '(a)') &
        '#  Step   Temperature     Kinetic      Potential     Total Energy    Pressure'
    WRITE (data_unit, '(a)') &
        '# -----  ------------  ------------  ------------  ------------  ------------'
    WRITE (data_unit, '(a)') '#'

    DO step = 1, step_num

        CALL refold_positions()

        pos = pos + deltat * vel + 0.5D+00 * deltat * deltat * acc
        CALL write_traj(traj_unit)
!
!  For constant T, rescale the velocity.
!
        IF (temp_constant .AND. 0.0D+00 < temperature) THEN
            CALL compute_temperature(ene_kin_aver, temperature)
            chi = SQRT(temp_requested / temperature)
            vel = chi * vel + 0.5D+00 * deltat * acc
        ELSE
            vel = vel + 0.5D+00 * deltat * acc
        END IF

        CALL compute_forces()

        vel = vel + 0.5D+00 * deltat * acc

        CALL compute_temperature(ene_kin_aver, temperature)

        ene_pot_aver = SUM(ene_pot) / REAL(n, kind=8)
        ene_tot_aver = ene_kin_aver + ene_pot_aver
!
!  For the pressure calculation, see the Allen and Tildesley book, section 2.4
!
        pressure = density * temperature + virial / volume

        WRITE (data_unit, '(i6,f14.6,f14.6,f14.6,f14.6,f14.6)') &
            step, temperature, ene_kin_aver, ene_pot_aver, ene_tot_aver, pressure
!
!  Accumulate statistics.
!
        temperature_sum = temperature_sum + temperature
        ene_kin_sum = ene_kin_sum + ene_kin_aver
        ene_pot_sum = ene_pot_sum + ene_pot_aver
        pressure_sum = pressure_sum + pressure

    END DO
!
!  Averages:
!
    WRITE (data_unit, '(a)') '#'
    WRITE (data_unit, '(a,f14.6,f14.6,f14.6,f14.6,f14.6)') &
        '# Means', &
        temperature_sum / REAL(step_num, kind=8), &
        ene_kin_sum / REAL(step_num, kind=8), &
        ene_pot_sum / REAL(step_num, kind=8), &
        (ene_kin_sum + ene_pot_sum) / REAL(step_num, kind=8), &
        pressure_sum / REAL(step_num, kind=8)

    CLOSE (unit=data_unit)
    CLOSE (unit=traj_unit)
    WRITE (*, '(a)') ''
    WRITE (*, '(a)') &
        '  Created graphics data file "'//TRIM(data_filename)//'".'

    CALL get_unit(command_unit)
    command_filename = 'md1_commands.txt'

    OPEN (unit=command_unit, file=command_filename, status='replace')
    WRITE (command_unit, '(a)') 'set term png'
    WRITE (command_unit, '(a)') 'set output "temperature.png"'
    WRITE (command_unit, '(a)') 'set grid'
    WRITE (command_unit, '(a)') 'set style data lines'
    WRITE (command_unit, '(a)') 'unset key'
    WRITE (command_unit, '(a)') 'set xlabel "<---Time--->"'
    WRITE (command_unit, '(a)') 'set ylabel "<---Temperature--->"'
    WRITE (command_unit, '(a)') 'set title "Temperature over Time"'
    WRITE (command_unit, '(a)') 'set timestamp'
    WRITE (command_unit, '(a,i4,a)') &
        'plot "'//TRIM(data_filename)//'" using 1:2 with lines'

    WRITE (command_unit, '(a)') 'set output "kinetic.png"'
    WRITE (command_unit, '(a)') 'set xlabel "<---Time--->"'
    WRITE (command_unit, '(a)') 'set ylabel "<---Kinetic Energy--->"'
    WRITE (command_unit, '(a)') 'set title "Kinetic Energy over Time"'
    WRITE (command_unit, '(a)') 'set timestamp'
    WRITE (command_unit, '(a,i4,a)') &
        'plot "'//TRIM(data_filename)//'" using 1:3 with lines'

    WRITE (command_unit, '(a)') 'set output "potential.png"'
    WRITE (command_unit, '(a)') 'set xlabel "<---Time--->"'
    WRITE (command_unit, '(a)') 'set ylabel "<---Potential Energy--->"'
    WRITE (command_unit, '(a)') 'set title "Potential Energy over Time"'
    WRITE (command_unit, '(a)') 'set timestamp'
    WRITE (command_unit, '(a,i4,a)') &
        'plot "'//TRIM(data_filename)//'" using 1:4 with lines'

    WRITE (command_unit, '(a)') 'set output "pressure.png"'
    WRITE (command_unit, '(a)') 'set xlabel "<---Time--->"'
    WRITE (command_unit, '(a)') 'set ylabel "<---Pressure--->"'
    WRITE (command_unit, '(a)') 'set title "Pressure over Time"'
    WRITE (command_unit, '(a)') 'set timestamp'
    WRITE (command_unit, '(a,i4,a)') &
        'plot "'//TRIM(data_filename)//'" using 1:6 with lines'

    WRITE (command_unit, '(a)') 'quit'
    CLOSE (unit=command_unit)
    WRITE (*, '(a)') &
        '  Created graphics command file "'//TRIM(command_filename)//'".'

    RETURN
END
SUBROUTINE get_unit(iunit)

!*****************************************************************************80
!
!! GET_UNIT returns a free FORTRAN unit number.
!
!  Discussion:
!
!    A "free" FORTRAN unit number is a value between 1 and 99 which
!    is not currently associated with an I/O device.  A free FORTRAN unit
!    number is needed in order to open a file with the OPEN command.
!
!    If IUNIT = 0, then no free FORTRAN unit could be found, although
!    all 99 units were checked (except for units 5, 6 and 9, which
!    are commonly reserved for console I/O).
!
!    Otherwise, IUNIT is a value between 1 and 99, representing a
!    free FORTRAN unit.  Note that GET_UNIT assumes that units 5 and 6
!    are special, and will never return those values.
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license.
!
!  Modified:
!
!    26 October 2008
!
!  Author:
!
!    John Burkardt
!
!  Parameters:
!
!    Output, integer ( kind = 4 ) IUNIT, the free unit number.
!
    IMPLICIT NONE

    INTEGER(kind=4) i
    INTEGER(kind=4) ios
    INTEGER(kind=4) iunit
    LOGICAL lopen

    iunit = 0

    DO i = 1, 99

        IF (i /= 5 .AND. i /= 6 .AND. i /= 9) THEN

            INQUIRE (unit=i, opened=lopen, iostat=ios)

            IF (ios == 0) THEN
                IF (.NOT. lopen) THEN
                    iunit = i
                    RETURN
                END IF
            END IF

        END IF

    END DO

    RETURN
END
SUBROUTINE initial_printout()

!*****************************************************************************80
!
!! INITIAL_PRINTOUT prints information on the run parameters.
!
!  Modified:
!
!    01 November 2005
!
!  Author:
!
!    Furio Ercolessi
!
    USE particles
    USE simulation_control

    IMPLICIT NONE

    WRITE (*, '(a)') ''
    WRITE (*, '(a)') '  Title:"'//TRIM(title)//'"'
    WRITE (*, '(a)') '  Input sample: "'//TRIM(sampin)//'".'

    IF (vel_acc) THEN
        WRITE (*, '(a)') '  (positions, velocities, accelerations read from file)'
    ELSE
        WRITE (*, '(a)') '  (only positions read from file)'
    END IF

    WRITE (*, '(a)') '  Output sample: "'//TRIM(sampout)//'".'

    WRITE (*, '(a,i8,a,f7.4,a,f12.4)') &
        '  Number of steps:', step_num, ', time step:', deltat, &
        ', total time:', step_num * deltat
    WRITE (*, '(a,i6)') '  Number of atoms:', n
    WRITE (*, '(a,3f12.6,a,f15.3)') &
        '  Box size:', box_size(1:dim), ', Volume:', volume

    IF (rho_change) THEN
        WRITE (*, '(a,f12.6,a)') '  Density:', density, ' (changed)'
    ELSE
        WRITE (*, '(a,f12.6,a)') '  Density:', density, ' (unchanged)'
    END IF

    IF (temp_constant) THEN
        WRITE (*, '(a,f12.6)') '  Constant T run with T =', temp_requested
    ELSE
        WRITE (*, '(a)') '  Free evolution run.'
    END IF

    RETURN
END
SUBROUTINE initialize()

!*****************************************************************************80
!
!! INITIALIZE controls the initialization procedure.
!
!  Discussion:
!
!    This routine is called once at the beginning, before the
!    time evolution.
!
!  Modified:
!
!    28 October 2005
!
!  Author:
!
!    Furio Ercolessi
!
    USE particles

    IMPLICIT NONE
!
!  Read the user directives controlling the simulation.
!
    CALL read_input()
!
!  Read the input sample containing the initial particle coordinates
!  and perhaps also velocities and accelerations.
!
    CALL read_sample()
!
!  Print information.
!
    CALL initial_printout()

    RETURN
END
SUBROUTINE read_input()

!*****************************************************************************80
!
!! READ_INPUT reads the parameters controlling the simulation.
!
!  Discussion:
!
!    This routine reads an input file from the user containing
!    the values of certain program parameters.
!
!  Modified:
!
!    28 October 2005
!
!  Author:
!
!    Furio Ercolessi
!
    USE simulation_control

    IMPLICIT NONE

    INTEGER(kind=4) io_status

    READ (*, '(a)', iostat=io_status) title

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_INPUT - Fatal error!'
        WRITE (*, '(a)') '  I/O error reading TITLE.'
        STOP
    END IF

    READ (*, '(a)', iostat=io_status) sampin

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_INPUT - Fatal error!'
        WRITE (*, '(a)') '  I/O error reading SAMPIN.'
        STOP
    END IF

    READ (*, '(a)', iostat=io_status) sampout

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_INPUT - Fatal error!'
        WRITE (*, '(a)') '  I/O error reading SAMPOUT.'
        STOP
    END IF

    READ (*, *, iostat=io_status) step_num

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_INPUT - Fatal error!'
        WRITE (*, '(a)') '  I/O error reading STEP_NUM.'
        STOP
    END IF

    READ (*, *, iostat=io_status) deltat

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_INPUT - Fatal error!'
        WRITE (*, '(a)') '  I/O error reading DELTAT.'
        STOP
    END IF

    READ (*, *, iostat=io_status) rho_requested

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_INPUT - Fatal error!'
        WRITE (*, '(a)') '  I/O error reading RHO_REQUESTED.'
        STOP
    END IF

    READ (*, *, iostat=io_status) temp_requested

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_INPUT - Fatal error!'
        WRITE (*, '(a)') '  I/O error reading TEMP_REQUESTED.'
        STOP
    END IF

    rho_change = (0.0D+00 < rho_requested)
    temp_constant = (0.0D+00 <= temp_requested)

    RETURN
END
SUBROUTINE read_sample()

!*****************************************************************************80
!
!! READ_SAMPLE reads the initial sample from file unit 1.
!
!  Modified:
!
!    28 October 2005
!
!  Author:
!
!    Furio Ercolessi
!
    USE particles
    USE simulation_control

    IMPLICIT NONE

    REAL(kind=8), DIMENSION(dim) :: AccAtomReal
    INTEGER(kind=4) i
    INTEGER(kind=4) io_status
    INTEGER(kind=4) io_unit
    INTEGER(kind=4) k
    REAL(kind=8), DIMENSION(dim) :: mass_center
    REAL(kind=8), DIMENSION(dim) :: PosAtomReal
    REAL(kind=8) scale
    REAL(kind=8), DIMENSION(dim) :: VelAtomReal

    CALL get_unit(io_unit)

    OPEN (unit=io_unit, file=sampin, status='old', &
          action='read', iostat=io_status)

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_SAMPLE - Fatal error!'
        WRITE (*, '(a)') '  Could not open the input file.'
        STOP
    END IF

    READ (io_unit, '(1x,l2,i7,3e23.15)', iostat=io_status) &
        vel_acc, n, box_size(1:dim)

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_SAMPLE - Fatal error!'
        WRITE (*, '(a)') '  Error reading line 1 of the input file.'
        STOP
    END IF

    IF (n <= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'READ_SAMPLE - Fatal error!'
        WRITE (*, '(a,i6)') '  N is ', n
        STOP
    END IF
!
!  Compute the volume and density.  They do not change in the run.
!
    volume = PRODUCT(box_size(1:dim))
    density = REAL(n, kind=8) / volume
!
!  Unless the user wants to change the density, in this case we do
!  it here:
!
    IF (rho_change) THEN
        scale = (density / rho_requested)**(1.0D+00 / dim)
        box_size(1:dim) = scale * box_size(1:dim)
        volume = PRODUCT(box_size(1:dim))
        density = REAL(n, kind=8) / volume
    END IF
!
!  Now that we know the system size, we can dynamically allocate the
!  arrays containing atomic information.
!
    ALLOCATE (acc(dim, n))
    ALLOCATE (ene_kin(n))
    ALLOCATE (ene_pot(n))
    ALLOCATE (pos(dim, n))
    ALLOCATE (vel(dim, n))
!
!  Read the coordinates from the file (one line per atom), normalize
!  them to the box size along each direction and store them.
!  Energies are set initially to zero.
!
    DO i = 1, n

        READ (io_unit, *, iostat=io_status) PosAtomReal(1:dim)

        IF (io_status /= 0) THEN
            WRITE (*, '(a)') ' '
            WRITE (*, '(a)') 'READ_SAMPLE - Fatal error!'
            WRITE (*, '(a)') '  Error reading PosAtomReal array.'
            STOP
        END IF

        pos(1:dim, i) = PosAtomReal(1:dim) / box_size(1:dim)

    END DO

    ene_pot(1:n) = 0.0D+00
    ene_kin(1:n) = 0.0D+00
!
!  For "new" samples (that is, samples just created by defining the atomic
!  coordinates and not the result of previous simulations), we have now
!  read everything, and velocities and accelerations are set to zero.
!
!  For samples which have been produced by previous simulations, we also
!  have to read velocities and accelerations.
!
!  The logical variable VEL_ACC distinguishes between these two cases.
!
    IF (vel_acc) THEN

        DO i = 1, n

            READ (io_unit, '(1x,3e23.15)', iostat=io_status) VelAtomReal

            IF (io_status /= 0) THEN
                WRITE (*, '(a)') ' '
                WRITE (*, '(a)') 'READ_SAMPLE - Fatal error!'
                WRITE (*, '(a)') '  Error reading VelAtomReal array.'
                STOP
            END IF

            vel(1:dim, i) = VelAtomReal / box_size(1:dim)

        END DO

        DO i = 1, n

            READ (io_unit, '(1x,3e23.15)', iostat=io_status) AccAtomReal

            IF (io_status /= 0) THEN
                WRITE (*, '(a)') ' '
                WRITE (*, '(a)') 'READ_SAMPLE - Fatal error!'
                WRITE (*, '(a)') '  Error reading AccAtomReal array.'
                STOP
            END IF

            acc(1:dim, i) = AccAtomReal / box_size(1:dim)

        END DO

    ELSE

        vel(1:dim, 1:n) = 0.0D+00

        acc(1:dim, 1:n) = 0.0D+00

    END IF
!
!  Compute the center of mass.
!
    mass_center(1:dim) = SUM(pos(1:dim, 1:n), dim=2) / REAL(n, kind=8)
!
!  Translate the atoms so that center of mass is at the origin.
!
    IF (.FALSE.) THEN

        WRITE (*, '(a)') ''
        WRITE (*, '(a)') 'READ_SAMPLE: Warning!'
        WRITE (*, '(a)') '  The coordinate data is translated to have'
        WRITE (*, '(a)') '  zero center of mass.'

        DO k = 1, dim
            pos(k, 1:n) = pos(k, 1:n) - mass_center(k)
        END DO

    ELSE

        WRITE (*, '(a)') ''
        WRITE (*, '(a)') 'READ_SAMPLE: Warning!'
        WRITE (*, '(a)') '  The coordinate data is NOT translated to have'
        WRITE (*, '(a)') '  zero center of mass.'

    END IF

    CLOSE (unit=io_unit)

    RETURN
END
SUBROUTINE refold_positions()

!*****************************************************************************80
!
!! REFOLD_POSITIONS folds exiting particles back into the box.
!
!  Discussion:
!
!    Periodic boundary conditions are used.
!
!  Modified:
!
!    28 October 2005
!
!  Author:
!
!    Furio Ercolessi
!
    USE particles

    IMPLICIT NONE

    WHERE (0.5D+00 < pos)
        pos = pos - 1.0D+00
    END WHERE

    WHERE (pos < -0.50D+00)
        pos = pos + 1.0D+00
    END WHERE

    RETURN
END
SUBROUTINE timestamp()

!*****************************************************************************80
!
!! TIMESTAMP prints the current YMDHMS date as a time stamp.
!
!  Example:
!
!    31 May 2001   9:45:54.872 AM
!
!  Licensing:
!
!    This code is distributed under the GNU LGPL license.
!
!  Modified:
!
!    18 May 2013
!
!  Author:
!
!    John Burkardt
!
!  Parameters:
!
!    None
!
    IMPLICIT NONE

    CHARACTER(len=8) ampm
    INTEGER(kind=4) d
    INTEGER(kind=4) h
    INTEGER(kind=4) m
    INTEGER(kind=4) mm
    CHARACTER(len=9), PARAMETER, DIMENSION(12) :: month = (/ &
                                          'January  ', 'February ', 'March    ', 'April    ', &
                                          'May      ', 'June     ', 'July     ', 'August   ', &
                                           'September', 'October  ', 'November ', 'December '/)
    INTEGER(kind=4) n
    INTEGER(kind=4) s
    INTEGER(kind=4) values(8)
    INTEGER(kind=4) y

    CALL DATE_AND_TIME(values=values)

    y = values(1)
    m = values(2)
    d = values(3)
    h = values(5)
    n = values(6)
    s = values(7)
    mm = values(8)

    IF (h < 12) THEN
        ampm = 'AM'
    ELSE IF (h == 12) THEN
        IF (n == 0 .AND. s == 0) THEN
            ampm = 'Noon'
        ELSE
            ampm = 'PM'
        END IF
    ELSE
        h = h - 12
        IF (h < 12) THEN
            ampm = 'PM'
        ELSE IF (h == 12) THEN
            IF (n == 0 .AND. s == 0) THEN
                ampm = 'Midnight'
            ELSE
                ampm = 'AM'
            END IF
        END IF
    END IF

    WRITE (*, '(i2,1x,a,1x,i4,2x,i2,a1,i2.2,a1,i2.2,a1,i3.3,1x,a)') &
        d, TRIM(month(m)), y, h, ':', n, ':', s, '.', mm, TRIM(ampm)

    RETURN
END
SUBROUTINE write_sample()

!*****************************************************************************80
!
!! WRITE_SAMPLE writes the final sample.
!
!  Discussion:
!
!    This sample file may be read by the BALLROOM program, for
!    visualization.  Since it only wants to read point coordinates,
!    the other data is "hidden" by "%" signs, which BALLROOM takes
!    as comment indicators.
!
!    This sample file may also be read as the input file for another
!    run of this program.  In that case, the routine which reads the
!    input data will skip over the comment character and "see"
!    the velocity and acceleration data.
!
!  Modified:
!
!    28 October 2005
!
!  Author:
!
!    Furio Ercolessi
!
    USE particles
    USE simulation_control

    IMPLICIT NONE

    REAL(kind=8), DIMENSION(dim) :: AccAtomReal
    INTEGER(kind=4) i
    INTEGER(kind=4) io_status
    INTEGER(kind=4) io_unit
    REAL(kind=8), DIMENSION(dim) :: PosAtomReal
    REAL(kind=8), DIMENSION(dim) :: VelAtomReal

    CALL get_unit(io_unit)

    OPEN (unit=io_unit, file=sampout, status='replace', &
          action='write', iostat=io_status)

    IF (io_status /= 0) THEN
        WRITE (*, '(a)') ' '
        WRITE (*, '(a)') 'WRITE_SAMPLE - Fatal error!'
        WRITE (*, '(a)') '  Could not open the output file.'
        STOP
    END IF
!
!  VEL_ACC = TRUE because we will write velocities and accelerations.
!
    vel_acc = .TRUE.
!
!  The '%' is a comment character, and allows information to be inserted
!  into the file that can be used by some postprocessing programs,
!  and ignored by others.
!
    WRITE (io_unit, '(a1,l2,i7,3e23.15)') '%', vel_acc, n, box_size(1:dim)
!
!  Multiply coordinates (which are scaled by the box size) by box_size in
!  order to have them in real, unscaled units, then write them in the
!  file (one line per atom).
!
    DO i = 1, n
        PosAtomReal(1:dim) = pos(1:dim, i) * box_size(1:dim)
        WRITE (io_unit, '(1x,3e23.15)') PosAtomReal(1:dim)
    END DO
!
!  Do the same for velocities and accelerations.
!
    DO i = 1, n
        VelAtomReal(1:dim) = vel(1:dim, i) * box_size(1:dim)
        WRITE (io_unit, '(a1,3e23.15)') '%', VelAtomReal(1:dim)
    END DO

    DO i = 1, n
        AccAtomReal(1:dim) = acc(1:dim, i) * box_size(1:dim)
        WRITE (io_unit, '(a1,3e23.15)') '%', AccAtomReal(1:dim)
    END DO

    CLOSE (unit=io_unit)

    RETURN
END
SUBROUTINE write_traj(traj_unit)
    USE simulation_control
    USE particles
    INTEGER :: traj_unit
    WRITE (traj_unit, '(I0)') n
    WRITE (traj_unit, '(A10,9F16.8)') 'Lattice=', &
        box_size(1), 0., 0., &
        0., box_size(2), 0., &
        0., 0., box_size(3)
    DO i = 1, n
        WRITE (traj_unit, '(A5,3F16.8)') 'He', pos(1:dim, i) * box_size(1:dim)
    END DO
END SUBROUTINE write_traj
