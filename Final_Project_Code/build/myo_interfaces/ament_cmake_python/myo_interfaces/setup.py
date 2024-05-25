from setuptools import find_packages
from setuptools import setup

setup(
    name='myo_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('myo_interfaces', 'myo_interfaces.*')),
)
